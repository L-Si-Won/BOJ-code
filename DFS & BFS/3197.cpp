#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int r, c;
char arr[1500][1500];
bool visit[1500][1500];
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
queue<pair<int, int>> swan_q, swan_nq, q, nq;
pair<int, int> swan_pos;
bool Find;

void swan_bfs(){
    while(!swan_q.empty() && Find==false){
        int x=swan_q.front().first;
        int y=swan_q.front().second;
        swan_q.pop();

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<r && ny<c){
                if(visit[nx][ny]==false){
                    if(arr[nx][ny]=='.'){
                        visit[nx][ny]=true;
                        swan_q.push({nx, ny});
                    }
                    else if(arr[nx][ny]=='L'){
                        visit[nx][ny]=true;
                        Find=true;
                        break;
                    }
                    else if(arr[nx][ny]=='X'){
                        visit[nx][ny]=true;
                        swan_nq.push({nx, ny});
                    }
                }
            }
        }
    }
}

void water_bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<r && ny<c){
                if(arr[nx][ny]=='X'){
                    arr[nx][ny]='.';
                    nq.push({nx, ny});
                }
            }
        }
    }
}

void solve(){
    int day=0;
    swan_q.push(swan_pos);
    visit[swan_pos.first][swan_pos.second]=true;

    while(Find==false){
        swan_bfs();
        if(Find==false){
            water_bfs();
            q=nq;
            swan_q=swan_nq;
            while(!nq.empty()) nq.pop();
            while(!swan_nq.empty()) swan_nq.pop();
            day++;
        }
    }
    cout << day;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        string s;
        cin >> s;
        for(int j=0; j<c; j++){
            arr[i][j]=s[j];
            if(arr[i][j]!='X') q.push({i, j});
            if(arr[i][j]=='L') swan_pos={i, j};
        }
    }
    solve();
}
