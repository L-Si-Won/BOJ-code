#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, answer = 2e9;
int dist[101], kb[101];
vector<int> v[101];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({start, 0});
    dist[start] = 0;

    while (!q.empty()) {
        int cur = q.top().first;
        int dis = q.top().second;
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];

            if (dis + 1 < dist[next]) {
                dist[next] = dis + 1;
                q.push({next, dis +1});
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[j] = 2e9;
        }
        dijkstra(i);

        for (int j = 1; j <= n; j++) {
            kb[i] += dist[j];
        }
    }

    answer = 1;
    for (int i = 2; i <= n; i++) {
        if (kb[i] < kb[answer]) {
            answer = i;
        }
    }

    cout << answer;
}
