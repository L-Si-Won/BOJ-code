#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int map[100][100];
bool visit[100][100];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};
int map_order_cnt=1;
int MIN=2e9;

void map_order(int x, int y){
  queue<pair<int, int>> q;
  q.push({x, y});
  visit[x][y]=true;
  map[x][y]=map_order_cnt;

  while(!q.empty()){
    int cur_x=q.front().first;
    int cur_y=q.front().second;
    q.pop();

    for(int i=0; i<4; i++){
      int nx=cur_x+dx[i];
      int ny=cur_y+dy[i];
      if(nx>=0 && ny>=0 && ny<n && nx<n){
        if(visit[nx][ny]==false && map[nx][ny]==-1){
          visit[nx][ny]=true;
          map[nx][ny]=map_order_cnt;
          q.push({nx, ny});
        }
      }
    }
  }
  map_order_cnt++;
}

void solve(int order){
  queue<pair<int, int>> q;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(map[i][j]==order){
        visit[i][j]=true;
        q.push({i, j});
      }
    }
  }

  int result=0;
  while(!q.empty()){
    int size=q.size();
    for(int i=0; i<size; i++){
      int x=q.front().first;
      int y=q.front().second;
      q.pop();

      for(int j=0; j<4; j++){
        int nx=x+dx[j];
        int ny=y+dy[j];
        if(nx>=0 && ny>=0 && nx<n && ny<n){
          if(map[nx][ny]!=0 && map[nx][ny]!=order){
            MIN=min(MIN, result);
            return ;
          }
          else if(map[nx][ny]==0 && visit[nx][ny]==false){
            visit[nx][ny]=true;
            q.push({nx, ny});
          }
        }
      }
    }
    result++;
  }
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> map[i][j];
      if(map[i][j]==1)
        map[i][j]=-1;
    }
  }

  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(map[i][j]==-1 && visit[i][j]==false)
        map_order(i, j);
  
  for(int i=1; i<map_order_cnt; i++){
    memset(visit, false, sizeof(visit));
    solve(i);
  }
  cout << MIN;
}
