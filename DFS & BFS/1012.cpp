#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int t, m, n, k, answer;
int arr[50][50];
bool visit[50][50];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y]=true;

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(arr[nx][ny]==1 && visit[nx][ny]==false){
                    visit[nx][ny]=true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        for(int i=0; i<k; i++){
            int x, y;
            cin >> x >> y;
            arr[y][x]=1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1 && visit[i][j]==false){
                    bfs(i, j);
                    answer++;
                }
            }
        }
        cout << answer << "\n";

        for(int i=0; i<50; i++)
            for(int j=0; j<50; j++)
                arr[i][j]=0;
        memset(visit, false, sizeof(visit));
        answer=0;
    }
}
