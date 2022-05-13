#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define R 1
#define B 2
int v, e, k;
vector<int> arr[20001];
int visit[20001];

void dfs(int cur){
    if(!visit[cur]) visit[cur]=R;
    for(int i=0; i<arr[cur].size(); i++){
        int next=arr[cur][i];
        if(visit[next]==false){
            if(visit[cur]==R) visit[next]=B;
            else if(visit[cur]==B) visit[next]=R;
            dfs(next);
        }
    }
}

void bfs(int cur){
    queue<int> q;
    q.push(cur);
    visit[cur]=true;
    while(!q.empty()){
        int c=q.front();
        q.pop();
        cout << c << " ";
        for(int i=0; i<arr[c].size(); i++){
            int next=arr[c][i];
            if(visit[next]==false){
                visit[next]=true;
                q.push(next);
            }
        }
    }
}

bool isBipartiteGraph() {
    for (int i = 1; i <= v; i++) {
        int gsize = arr[i].size();
        for (int j = 0; j < gsize; j++) {
            int next = arr[i][j];
            if (visit[i] == visit[next]) {
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> k;
    for(int i=0; i<k; i++){
        cin >> v >> e;
        for(int j=0; j<e; j++){
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        
        for(int j=1; j<v+1; j++)
            if(!visit[j])
                dfs(j);

        if(isBipartiteGraph()) cout << "YES\n";
        else cout << "NO\n";

        for(int j=0; j<v+1; j++)
            arr[j].clear();
        memset(visit, 0, sizeof(visit));
    }
}