#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n, m, t, s, g, h, a, b, d;
vector<pair<int, int>> v[2001]; //도로(교차로, 거리)
vector<int> dist; //목적지 후보
vector<int> ans;
int S[2001], G[2001], H[2001];

void dijkstra(int start, int A[2001]){
    queue<pair<int, int>> q; //거리, 교차로
    q.push({0, start});
    A[start]=0;

    while(!q.empty()){
        int cost=q.front().first;
        int cur=q.front().second;
        q.pop();

        for(int i=0; i<v[cur].size(); i++){
            int next=v[cur][i].first;
            int ncost=v[cur][i].second;
            if(A[next]>cost+ncost){
                A[next]=cost+ncost;
                q.push({A[next], next});
            }
        }
    }
}

void solve(){
    dijkstra(s, S);
    dijkstra(g, G);
    dijkstra(h, H);
    for(int i=0; i<dist.size(); i++){
        if(S[dist[i]]==S[g]+G[h]+H[dist[i]]) ans.push_back(dist[i]);
        else if(S[dist[i]]==S[h]+H[g]+G[dist[i]]) ans.push_back(dist[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;
    while(T--){
        for(int i=0; i<2001; i++){
            v[i].clear();
            S[i]=2e9;
            G[i]=2e9;
            H[i]=2e9;
        }
        dist.clear();
        ans.clear();
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for(int i=0; i<m; i++){
            cin >> a >> b >> d;
            v[a].push_back({b, d});
            v[b].push_back({a, d});
        }
        for(int i=0; i<t; i++){
            int temp;
            cin >> temp;
            dist.push_back(temp);
        }
        solve();
    }
}
