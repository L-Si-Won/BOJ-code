#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[1000][1000], dist[1000][1000];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, int> goal;

void bfs () {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, goal});
    dist[goal.first][goal.second] = 0;

    while (!q.empty()) {
        int dis = q.top().first;
        int cx = q.top().second.first;
        int cy = q.top().second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int ndis = dis + 1;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (map[nx][ny] != 0 && ndis < dist[nx][ny]) {
                    dist[nx][ny] = ndis;
                    q.push({ndis, {nx, ny}});
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            dist[i][j] = 2e9;

            if (map[i][j] == 2) {
                goal = {i, j};
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == 2e9) {
                if (map[i][j] == 0) {
                    cout << "0 ";
                } else {
                    cout << "-1 ";
                }
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
