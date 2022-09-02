#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int arr[100][100]; //지도
bool visit[100][100]; //방문확인
bool fall[100][100]; //잠겼는지 확인
int MAX; //영역 최대 개수
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y]=true;

    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cur_x+dx[i];
            int ny=cur_y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<n){
                if(visit[nx][ny]==false && fall[nx][ny]==false){
                    q.push({nx, ny});
                    visit[nx][ny]=true;
                }
            }
        }
    }
}

int solve(int stair){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(arr[i][j]<=stair)
                fall[i][j]=true;

    int temp_max=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j]==false && fall[i][j]==false){
                bfs(i, j);
                temp_max++;
            }
        }
    }
    return temp_max;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    for(int i=0; i<=99; i++){
        int sol=solve(i);
        if(sol==0) break;
        MAX=max(MAX, sol);
        memset(visit, false, sizeof(visit));
        memset(fall, false, sizeof(fall));
    }
    cout << MAX;
}
