#include <iostream>
#include <vector>

using namespace std;

int n, k, answer = 1e9;
vector<pair<int, int>> v;
pair<int, int> safe[3];

void sol() {
    int max_dist = -1;
    
    for (int i = 0; i < v.size(); i++) {
        int dist = 2e9;

        for (int j = 0; j < k; j++) {
            int dist2 = abs(v[i].first - safe[j].first) + abs(v[i].second - safe[j].second);
            dist = min(dist, dist2);
        }
        max_dist = max(max_dist, dist);
    }

    answer = min(answer, max_dist);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    for (int i = 0; i < v.size(); i++) {
        safe[0] = v[i];

        if (k >= 2) {
            for (int j = i + 1; j < v.size(); j++) {
                safe[1] = v[j];

                if (k >= 3) {
                    for (int l = j + 1; l < v.size(); l++) {
                        safe[2] = v[l];
                        sol();
                    }
                } else {
                    sol();
                }
            }
        } else {
            sol();
        }
    }

    cout << answer;
}
