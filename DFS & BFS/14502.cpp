#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m, answer, birus_cnt;
int map_org[8][8], map[8][8];
pair<int, int> birus[10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int birus_idx) {
    queue<pair<int, int>> q;
    q.push(birus[birus_idx]);

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (map[nx][ny] == 0) {
                    map[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map_org[i][j];
            if (map_org[i][j] == 2) {
                birus[birus_cnt++] = {i, j};
            }
        }
    }

    for (int w1x = 0; w1x < n; w1x++) {
        for (int w1y = 0; w1y < m; w1y++) {
            if (map_org[w1x][w1y] != 0) {
                continue;
            }

            for (int w2x = w1x; w2x < n; w2x++) { 
                for (int w2y = 0; w2y < m; w2y++) {
                    if (w2x == w1x && w2y == w1y) {
                        continue;
                    }
                    if (map_org[w2x][w2y] != 0) {
                        continue;
                    }

                    for (int w3x = w2x; w3x < n; w3x++) {
                        for (int w3y = 0; w3y < m; w3y++) {
                            if ((w3x == w2x && w3y == w2y) || (w3x == w1x && w3y == w1y)) {
                                continue;
                            }
                            if (map_org[w3x][w3y] != 0) {
                                continue;
                            }

                            memcpy(map, map_org, sizeof(map));

                            map[w1x][w1y] = 1;
                            map[w2x][w2y] = 1;
                            map[w3x][w3y] = 1;

                            int sum = 0;
                            for (int i = 0; i < birus_cnt; i++) {
                                bfs(i);
                            }
                            for (int i = 0; i < n; i++) {
                                for (int j = 0; j < m; j++) {
                                    if (map[i][j] == 0) {
                                        sum++;
                                    }
                                }
                            }

                            answer = max(answer, sum);
                        }
                    }
                }
            }
        }
    }

    cout << answer;
}
