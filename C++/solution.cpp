#include <bits/stdc++.h>
using namespace std;

int a[100001]={0, };
bool cmp(int t1, int t2){ // 정렬 기준
  return a[t1]<a[t2];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> v[100001]; int ch[100001]={0, };
  vector<int> res; vector<int> cp;

  int n; cin>>n;
  for(int i=0; i<n-1; i++){
    int t1, t2; cin>>t1>>t2;
    v[t1].emplace_back(t2); v[t2].emplace_back(t1);
  }
  for(int i=1; i<=n; i++){
    int tmp; cin>>tmp; a[tmp]=i;
    cp.emplace_back(tmp);
  }
  if(a[1]!=1) { cout<<"0"; return 0; } // 예외처리

  for(int i=1; i<=n; i++) sort(v[i].begin(), v[i].end(), cmp);
  queue<int> q;
  ch[1]=1; q.push(1);

  while(!q.empty()){
    int p = q.front(); q.pop();
    res.emplace_back(p);

    for(int i=0; i<v[p].size(); i++){
      if(ch[v[p][i]]==0){
        ch[v[p][i]]=1; q.push(v[p][i]);
      }
    }
  } // while문 끝

  if(cp==res) cout<<"1";
  else cout<<"0";
  return 0;
}