#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> v[32001]; //자신의 뒤에 있는 사람
int cnt[32001]; //자신보다 앞서는 사람의 수

void solve(){
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(cnt[i]==0) q.push(i);
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        cout << cur << " ";

        for(int i=0; i<v[cur].size(); i++){
            int next=v[cur][i];
            cnt[next]--;

            if(cnt[next]==0) q.push(next);
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
        cnt[b]++;
        v[a].push_back(b);
    }

    solve();
}
