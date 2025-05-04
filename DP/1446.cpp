#include <iostream>
#include <vector>

using namespace std;

int n, d, dist[10001];
vector<pair<int, int>> v[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    for (int i = 0; i <= d; i++) {
        dist[i] = 2e9;
    }

    for (int i = 0; i <= d; i++) {
        if (i == 0) {
            dist[0] = 0;

            for (int j = 0; j < v[0].size(); j++) {
                dist[v[0][j].first] = min(dist[v[0][j].first], v[0][j].second);
            }
        } else {
            dist[i] = min(dist[i], dist[i - 1] + 1);

            for (int j = 0; j < v[i].size(); j++) {
                dist[v[i][j].first] = min(dist[v[i][j].first], dist[i] + v[i][j].second);
            }
        }
    }

    cout << dist[d];
}
