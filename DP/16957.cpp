#include <iostream>

using namespace std;

int r, c;
int arr[501][501];
int answer[501][501];
pair<int, int> dp[501][501];
int dx[]={1, 0, -1, 0, 1, 1, -1, -1};
int dy[]={0, 1, 0, -1, 1, -1, 1, -1};

bool small_check(int x, int y){ //자신이 가장 작은지 확인
    bool flag=true;
    for(int i=0; i<8; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if(nx>=0 && ny>=0 && nx<r && ny<c){
            if(arr[x][y]>=arr[nx][ny]) flag=false;
        }
    }
    return flag;
}

void dfs(int start_x, int start_y, int x, int y){
    if(answer[x][y]!=0){ //찾아간 곳이 가장 작은 곳들 중 하나면
        answer[x][y]++;
        dp[start_x][start_y]={x, y};
        return;
    }
    if(dp[x][y].first!=-1){ //갈 곳이 이미 정해져 있다면
        answer[dp[x][y].first][dp[x][y].second]++;
        dp[start_x][start_y]=dp[x][y];
        return;
    }
    pair<int, int> MIN={x, y};
    for(int i=0; i<8; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx>=0 && ny>=0 && nx<r && ny<c){
            if(arr[nx][ny]<arr[MIN.first][MIN.second]){
                MIN={nx, ny};
            }
        }
    }
    
    dfs(start_x, start_y, MIN.first, MIN.second);
}

void solve(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(answer[i][j]==0){
                dfs(i, j, i, j);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<r; i++){ //공이 모일 곳들 미리 선별
        for(int j=0; j<c; j++){
            if(small_check(i, j)==true){
                answer[i][j]++;
                dp[i][j]={i, j};
            }
        }
    }

    for(int i=0; i<r; i++){ //dp초기화
        for(int j=0; j<c; j++){
            dp[i][j]={-1, -1};
        }
    }

    solve();

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}
