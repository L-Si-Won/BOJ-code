#include <iostream>
#include <vector>

using namespace std;

int v, e, disc[10001], disc_cnt;
vector<int> g[10001];
bool answer[10001];

int dfs(int node, bool root){
    disc[node]=++disc_cnt;
    int ret=disc[node];

    int child=0;
    for(int i=0; i<g[node].size(); i++){
        int next=g[node][i];
        if(disc[next]==0){
            child++;

            //node의 자식이 만나는 최소 노드
            int first=dfs(next, false);

            if(root==false && first>=disc[node])
                answer[node]=true;
            ret=min(ret, first);
        }
        else ret=min(ret, disc[next]);
    }

    if(root==true && child>=2) answer[node]=true;

    return ret;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i=1; i<=v; i++)
        if(disc[i]==0)
            dfs(i, true);

    int cnt=0;
    for(int i=1; i<=v; i++)
        if(answer[i]==true) cnt++;
    cout << cnt << "\n";

    for(int i=1; i<=v; i++)
        if(answer[i]==true)
            cout << i << " ";
}
