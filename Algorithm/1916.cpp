#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

int n, m, s, e;
int g[1001][1001];
int dist[1001];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({s, 0});
    dist[s] = 0;

    while (!q.empty()) {
        int cur = q.top().first;
        int cost = q.top().second;
        q.pop();

        for (int i = 1; i <= n; i++) {
            int next = i;
            int ncost = g[cur][next];

            if (ncost == INF) {
                continue;
            }

            if (cost + ncost < dist[next]) {
                dist[next] = cost + ncost;
                q.push({next, dist[next]});
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        g[i][i] = 0;
        dist[i] = INF;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cin >> s >> e;

    dijkstra();

    cout << dist[e];
}
