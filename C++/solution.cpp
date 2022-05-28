#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
vector<int> v[100001];
int parent[100001];
bool visit[100001];

void solve(){
    visit[1]=true;
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int cur=q.front();
        q.pop();
        
        for(int i=0; i<v[cur].size(); i++){
            int next=v[cur][i];
            if(visit[next]==false){
                q.push(next);
                visit[next]=true;
                parent[next]=cur;
            }
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
    solve();
    for(int i=2; i<=n; i++){
        cout << parent[i] << "\n";
    }
}