#include <iostream>
#include <queue>

using namespace std;

int h, w; //행, 열
char arr[100][100];
pair<int, int> c1={-1, -1};
pair<int, int> c2={-1, -1};
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
int cnt[100][100];

void solve(){ //웬만하면 해당 좌표의 정보는 큐에 저장하도록 하자!
    queue<pair<pair<int, int>, pair<int, int>>> q; //좌표, 거울 수, 진행방향
    q.push({c1, {0, -1}});
    cnt[c1.first][c1.second]=0;

    while(!q.empty()){
        int x=q.front().first.first;
        int y=q.front().first.second;
        int mir=q.front().second.first;
        int dir=q.front().second.second;
        q.pop();
        
        for(int i=0; i<4; i++){ //순서 : 하(0), 우(1), 상(2), 좌(3)
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<h && ny<w){
                if(arr[nx][ny]!='*'){
                    int temp=mir;
                    if(dir!=i) temp++;
                    if(cnt[nx][ny]>=temp){
                        cnt[nx][ny]=temp;
                        q.push({{nx, ny}, {temp, i}});
                    }
                }
            }
        }
    }
    cout << cnt[c2.first][c2.second]-1 <<"\n"; //처음에 무조건 +1되므로 -1해주기
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> w >> h;
    for(int i=0; i<h; i++){
        string s;
        cin >> s;
        for(int j=0; j<w; j++){
            arr[i][j]=s[j];
            if(arr[i][j]=='C'){
                if(c1.first==-1)
                    c1={i, j};
                else
                    c2={i, j};
            }
            cnt[i][j]=2e9;
        }
    }
    solve();
}