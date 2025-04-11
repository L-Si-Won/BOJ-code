#include <iostream>
#include <vector>

using namespace std;

int n, m, map[50][50];
int answer = 2e9;
bool close[50][50];
vector<pair<int, int>> home, chi;

void dfs(int check_point, int open_cnt) {
    if (open_cnt > m) {
        return;
    }

    int city_chi_dist = 0;
    for (int i = 0; i < home.size(); i++) {
        int hr = home[i].first;
        int hc = home[i].second;
        int chi_dist = 2e9;

        for (int j = 0; j < chi.size(); j++) {
            int cr = chi[j].first;
            int cc = chi[j].second;
            int dist;

            if (!close[cr][cc]) {
                dist = abs(cr - hr) + abs(cc - hc);
                chi_dist = min(chi_dist, dist);
            }
        }

        city_chi_dist += chi_dist;
    }

    answer = min(answer, city_chi_dist);

    for (int i = check_point + 1; i < chi.size(); i++) {
        int r = chi[i].first;
        int c = chi[i].second;

        if (close[r][c]) {
            close[r][c] = false;
            dfs(i, open_cnt + 1);
            close[r][c] = true;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                home.push_back({i, j});
            } else if(map[i][j] == 2) {
                chi.push_back({i, j});
            }

            close[i][j] = true;
        }
    }

    for (int i = 0; i < chi.size(); i++) {
        int r = chi[i].first;
        int c = chi[i].second;

        close[r][c] = false;
        dfs(i, 1);
        close[r][c] = true;
    }

    cout << answer;
}
