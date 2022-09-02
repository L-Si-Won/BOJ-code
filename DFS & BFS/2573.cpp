#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m; //행 열
int arr[300][300];
int temp_arr[300][300];
bool visit[300][300];
int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

void ice_cnt(int x, int y){
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
                if(visit[nx][ny]==false && arr[nx][ny]!=0){
                    visit[nx][ny]=true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void ice_melt(){ //동시에 녹는 것을 표현하기 위해 temp_arr사용
    memset(temp_arr, 0, sizeof(temp_arr));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]!=0){
                int temp=arr[i][j];
                for(int k=0; k<4; k++){
                    int cx=i+dx[k];
                    int cy=j+dy[k];
                    if(cx>=0 && cy>=0 && cx<n && cy<m)
                        if(arr[cx][cy]==0)
                            temp--;
                }
                if(temp<0) temp=0;
                temp_arr[i][j]=temp;
            }
            else temp_arr[i][j]=0;
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            arr[i][j]=temp_arr[i][j];
}

void solve(){
    int year=0;
    while(1){
        int ice=0; //year년 후 빙산 개수
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visit[i][j]==false && arr[i][j]!=0){
                    ice_cnt(i, j);
                    ice++;
                }
            }
        }
        if(ice==0){//다 녹았을 경우
            cout << "0";
            break;
        }
        if(ice>=2){
            cout << year;
            break;
        }
        memset(visit, false, sizeof(visit));
        ice_melt();
        year++;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    solve();
}
