#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<int> v[2000];
bool visit[2000];
bool ans=false;

void dfs(int cnt, int cur){
    if(cnt==4){
        ans=true;
        return ;
    }

    for(int i=0; i<v[cur].size(); i++){
        if(visit[v[cur][i]]==false){
            int nxt=v[cur][i];
            visit[nxt]=true;
            dfs(cnt+1, nxt);
            visit[nxt]=false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        memset(visit, false, sizeof(bool)*2000);
        visit[i]=true;
        dfs(0, i);
        if(ans) break;
    }
    cout << ans;
}