#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e, answer = 2e9;
vector<pair<int, int>> vil[401];
int dist[401];

void bfs(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});

    while (!q.empty()) {
        int dis = q.top().first;
        int cur = q.top().second;
        q.pop();

        if (dis != 0  && cur == start) {
            answer = min(answer, dis);
            return;
        }
        if (dis > dist[cur]) {
            continue;
        }

        for (int i = 0; i < vil[cur].size(); i++) {
            int next = vil[cur][i].first;
            int ndis = dis + vil[cur][i].second;

            if (ndis < dist[next]) {
                dist[next] = ndis;
                q.push({ndis, next});
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vil[a].push_back({b, c});
    }

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            dist[j] = 2e9;
        }
        bfs(i);
    }

    if (answer == 2e9) {
        cout << -1;
    } else {
        cout << answer;
    }
}
