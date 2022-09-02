#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, k, arr[100][100];
bool visit[100][100];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};
vector<int> v;
int answer;

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y]=true;
    int area=1;

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=0 && ny>=0 && nx<m && ny<n){
                if(arr[nx][ny]==0 && visit[nx][ny]==false){
                    visit[nx][ny]=true;
                    q.push({nx, ny});
                    area++;
                }
            }
        }
    }

    return area;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> k;
    while(k--){
        int ldx, ldy, rux, ruy;
        cin >> ldx >> ldy >> rux >> ruy;
        int lux=ldx, luy=ruy, rdx=rux, rdy=ldy; //좌상단, 우하단 좌표

        //좌표를 인덱스로 표현
        int left_idx_m=m-luy;
        int left_idx_n=lux;
        int right_idx_m=m-rdy-1;
        int right_idx_n=rdx-1;

        //인덱스를 기반으로 사각형 표현
        for(int i=left_idx_m; i<=right_idx_m; i++)
            for(int j=left_idx_n; j<=right_idx_n; j++)
                arr[i][j]=1;
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0 && visit[i][j]==false){
                v.push_back(bfs(i, j));
                answer++;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << answer << "\n";
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
}
