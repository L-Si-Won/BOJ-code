#include <iostream>

using namespace std;

int arr[500][500];
int m, n, h; //행 열
bool visit[500][500];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
int dp[500][500];

int solve(int x, int y){
    if(x==m-1 && y==n-1) return 1;
    if(visit[x][y]==true) return dp[x][y];
    visit[x][y]=true;
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<m && ny<n)
            if(arr[nx][ny]<arr[x][y])
                dp[x][y]+=solve(nx, ny);
    }
    return dp[x][y];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    cout << solve(0, 0);
}
