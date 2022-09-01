#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e, start;
vector<pair<int, int>> graph[20011]; //(도착지점, 가중치)
int dist[20011];

void solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start}); //(노드, 가중치)
    dist[start]=0;

    while(!q.empty()){
        int cost=q.top().first;
        int cur=q.top().second;
        q.pop();

        for(int i=0; i<graph[cur].size(); i++){
            int next=graph[cur][i].first;
            int ncost=graph[cur][i].second;

            if(dist[next]>cost+ncost){
                dist[next]=cost+ncost;
                q.push(make_pair(dist[next], next));
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(dist[i]==2e9) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> v >> e >> start;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    for(int i=1; i<=v; i++) dist[i]=2e9;

    solve();
}
