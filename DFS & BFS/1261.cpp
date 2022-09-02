#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[102][102];
bool visit[102][102];
int dp[102][102];
int dx[]={0, 0, 1, -1};
int dy[]={-1, 1, 0, 0};
int ans=2e9;

void bfs(){
  queue<pair<int, int>> q;
  q.push({1, 1});
  visit[1][1]=true;
  
  while(!q.empty()){
    int x=q.front().first; //열
    int y=q.front().second; //행
    q.pop();

    if(x==n && y==m){
      ans=min(ans, dp[m][n]);
    }

    for(int i=0; i<4; i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      int cur_dp=dp[y][x];
      if(nx>=1 && ny>=1 && nx<=n && ny<=m){
        if(arr[ny][nx]==0){
          if(visit[ny][nx]==false || dp[ny][nx]>cur_dp){
            visit[ny][nx]=true;
            dp[ny][nx]=cur_dp;
            q.push({nx, ny});
          }
        }
        else if(arr[ny][nx]==1){
          if(visit[ny][nx]==false || dp[ny][nx]>cur_dp+1){
            visit[ny][nx]=true;
            dp[ny][nx]=cur_dp+1;
            q.push({nx, ny});
          }
        }
      }
    }
  }
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> m; //n=열  m=행
  for(int i=1; i<=m; i++){
    string s;
    cin >> s;
    for(int j=0; j<n; j++)
      arr[i][j+1]=s[j]-'0';
  }
  bfs();
  cout << ans;
}
