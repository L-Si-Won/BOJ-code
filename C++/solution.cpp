#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool visit[100001];
int ans[100001];
vector<int> v[100001];
int dfs_ans[100001];
int cnt=1;
int order[100001];

bool comp(int i, int j){
  return order[i] < order[j];
}

void dfs(int cur){
  visit[cur]=true;
  dfs_ans[cnt++]=cur;
  for(int i=0; i<v[cur].size(); i++){
    int next=v[cur][i];
    if(visit[next]==false){
      dfs(next);
    }
  }
}

int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for(int i=0; i<n-1; i++){
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i=1; i<n+1; i++){
    cin >> ans[i];
    order[ans[i]]=i;
  }
  if(ans[1]!=1){
    cout << "0";
    return 0;
  }
  for(int i=1; i<n+1; i++)
    sort(v[i].begin(), v[i].end(), comp);
  dfs(1);
  for(int i=1; i<n+1; i++){
    if(ans[i]!=dfs_ans[i]){
      cout << "0";
      return 0;
    }
  }
  cout << "1";
}