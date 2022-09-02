#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v[101];
bool visit[101];
int cnt;

void dfs(int cur){
  visit[cur]=true;
  for(int i=0; i<v[cur].size(); i++){
    int next=v[cur][i];
    if(visit[next]==false){
      dfs(next);
      cnt++;
    }
  }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0; i<k; i++){
      int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    dfs(1);
    cout << cnt;
}
