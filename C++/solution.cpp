#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int n, m, answer;
char arr[50][50];
bool visit[50][50];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

int bfs(int x, int y){
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    visit[x][y]=true;
    int MAX=0;
    
    while(!q.empty()){
        int cx=get<0>(q.front());
        int cy=get<1>(q.front());
        int cd=get<2>(q.front());
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            int nd=cd+1;

            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(visit[nx][ny]==false && arr[nx][ny]=='L'){
                    q.push({nx, ny, nd});
                    visit[nx][ny]=true;
                    MAX=max(MAX, nd);
                }
            }
        }
    }

    return MAX;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++)
            arr[i][j]=s[j];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]=='L'){
                answer=max(answer, bfs(i, j));
                memset(visit, false, sizeof(visit));
            }
        }
    }
    
    cout << answer;
}