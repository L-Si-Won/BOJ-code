#include <iostream>
#include <vector>

using namespace std;

int n, m1, m2, k;
vector<int> v[101];
bool visit[101];

void dfs(int cur, int dist){
    visit[cur]=true;
    if(cur==m2){
        cout << dist;
        exit(0);
    }
    for(int i=0; i<v[cur].size(); i++){
        if(visit[v[cur][i]]==false){
            dfs(v[cur][i], dist+1);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m1 >> m2 >> k;
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(m1, 0);
    cout << "-1";
}