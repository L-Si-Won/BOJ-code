#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n;
int clip;
int scrn=1;
queue<tuple<int, int, int>> q; //{scrn, clip, time}
bool visit[1001][1001];

void solve(){
  q.push({1, 0, 0});
  visit[1][0]=true;

  while(!q.empty()){
    int s=get<0>(q.front());
    int c=get<1>(q.front());
    int t=get<2>(q.front());
    q.pop();

    if(s==n){
      cout << t;
      exit(0);
    }
    
    for(int i=0; i<3; i++){
      if(i==0){ //화면이모티콘을 클립보드에 복사저장
        if(visit[s][s]==false){
          q.push({s, s, t+1});
          visit[s][s]=true;
        }
      }
      else if(i==1){ //클립보드이모티콘을 화면에 붙여넣기
        if(s+c<=1000){
          if(visit[s+c][c]==false){
            q.push({s+c, c, t+1});
            visit[s+c][c]=true;
          }
        }
      }
      else if(i==2){ //화면이모티콘 하나 삭제
        if(s-1>=0){
          if(visit[s-1][c]==false){
            q.push({s-1, c, t+1});
            visit[s-1][c]=true;
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

  cin >> n;
  solve();
}
