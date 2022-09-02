#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool visit[100001];
int visit_time[100001];

void bfs(){
  queue<int> q;
  q.push(n);
  visit[n]=true;

  while(!q.empty()){
    int cur=q.front();
    q.pop();

    if(cur==k){
      cout << visit_time[k];
      exit(0);
    }

    for(int i=0; i<3; i++){
      int next, time;
      if(i==0){
        next=cur*2;
        time=0;
      }
      else if(i==1){
        next=cur+1;
        time=1;
      }
      else if(i==2){
        next=cur-1;
        time=1;
      }
      
      if(next>=0 && next<=100000 && (visit[next]==false || visit_time[next]>visit_time[cur]+time)){
        q.push(next);
        visit[next]=true;
        visit_time[next]=visit_time[cur]+time;
      }
    }
  }
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  bfs();
}
