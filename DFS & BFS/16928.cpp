#include <iostream>
#include <queue>

using namespace std;

int n, m, map[101];
int sadary[101], snake[101];
int dist[101], answer = 2e9;

void bfs() {
    queue<pair<int, int>> q; // (pos, cnt)
    q.push({1, 0});
    dist[1] = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == 100) {
            answer = min(answer, cnt);
            continue;
        }

        if (sadary[cur] != 0) {
            int next = sadary[cur];
            int ncnt = cnt;
            
            if (ncnt < dist[next]) {
                dist[next] = ncnt;
                q.push({next, ncnt});
            }
        } else if (snake[cur] != 0) {
            int next = snake[cur];
            int ncnt = cnt;

            if (ncnt < dist[next]) {
                dist[next] = ncnt;
                q.push({next, ncnt});
            }
        } else {
            for (int i = 1; i <= 6; i++) {
                int next = cur + i;
                int ncnt = cnt + 1;

                if (next <= 100 && ncnt < dist[next]) {
                    dist[next] = ncnt;
                    q.push({next, ncnt});
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
        int x, y;
        cin >> x >> y;
        sadary[x] = y;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        snake[x] = y;
    }
    for (int i = 0; i <= 100; i++) {
        dist[i] = 2e9;
        map[i] = i;
    }

    bfs();

    cout << answer;
}
