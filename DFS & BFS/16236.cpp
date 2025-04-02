#include <iostream>
#include <queue>

using namespace std;

int n, map[20][20];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
pair<int, int> pos;
int sh_size = 2, answer, eat;

int bfs() {
    vector<pair<pair<int, int>, int>> v; // {{x, y}, dist}
    pair<pair<int, int>, int> eat_pos;
    int dist[20][20], res = 0;
    queue<pair<pair<int, int>, int>> q; // {{x, y}, dist}
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            dist[i][j] = 2e9;
        }
    }
    dist[pos.first][pos.second] = 0;
    q.push({pos, 0});

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (map[nx][ny] == 0 || map[nx][ny] == 9) {
                    if (dis + 1 < dist[nx][ny]) {
                        q.push({{nx, ny}, dis + 1});
                        dist[nx][ny] = dis + 1;
                    }
                } else {
                    if (sh_size == map[nx][ny]) {
                        if (dis + 1 < dist[nx][ny]) {
                            q.push({{nx, ny}, dis + 1});
                            dist[nx][ny] = dis + 1;
                        }
                    } else if (sh_size > map[nx][ny]) {
                        if (dis + 1 < dist[nx][ny]) {
                            dist[nx][ny] = dis + 1;
                            v.push_back({{nx, ny}, dis + 1});
                        }
                    }
                }
            }
        }
    }

    if (v.size() == 0) {
        return res;
    }

    eat_pos = v[0];
    for (int i = 1; i < v.size(); i++) {
        if (v[i].second < eat_pos.second) {
            eat_pos = v[i];
        } else if (v[i].second == eat_pos.second) {
            if (v[i].first.first < eat_pos.first.first) {
                eat_pos = v[i];
            } else if(v[i].first.first == eat_pos.first.first) {
                if (v[i].first.second < eat_pos.first.second) {
                    eat_pos = v[i];
                }
            }
        }
    }

    map[eat_pos.first.first][eat_pos.first.second] = 0;
    pos = eat_pos.first;
    res = eat_pos.second;
    eat++;
    if (eat == sh_size) {
        eat = 0;
        sh_size++;
    }
    return res;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                pos = {i, j};
            }
        }
    }

    while (1) {
        int cost = bfs();
        if (!cost) {
            break;
        }
        answer += cost;
    }

    cout << answer << "\n";
}
