#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, e, a, b, answer;
vector<pair<int, int>> v[801];
int dist[801];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // (pos, cost)
    dist[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        int cur = q.top().first;
        int cost = q.top().second;
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;

            if (cost + ncost < dist[next]) {
                dist[next] = cost + ncost;
                q.push({next, dist[next]});
            }
        }
    }
}

void sol() {
    bool flag1 = true, flag2 = true;

    for (int i = 1; i <= n; i++) {
        dist[i] = 2e9;
    }
    dijkstra(1);

    int route1 = dist[a];
    int route2 = dist[b];

    if (route1 == 2e9) flag1 = false;
    if (route2 == 2e9) flag2 = false;

    for (int i = 1; i <= n; i++) {
        dist[i] = 2e9;
    }
    dijkstra(a);

    if (flag1) route1 += dist[b];
    if (flag2) route2 += dist[b]; // dist(a->b) = dist(b->a)

    if (flag2) route2 += dist[n];

    for (int i = 1; i <= n; i++) {
        dist[i] = 2e9;
    }
    dijkstra(b);

    if (flag1) route1 += dist[n];

    if (!flag1 && !flag2) {
        answer = -1;
    } else {
        answer = min(route1, route2);
    }

    if (answer >= 2e9) {
        answer = -1;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> a >> b;

    sol();

    cout << answer;
}
