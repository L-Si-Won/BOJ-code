#include <iostream>
#include <queue>

using namespace std;

long long a, b;
int answer = 2e9;

void sol() {
    queue<pair<long long, int>> q; // {value, calc_cnt}
    q.push({a, 0});

    while (!q.empty()) {
        long long val = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (val == b) {
            answer = min(answer, cnt);
            continue;
        }

        if (val * 2 <= b) {
            q.push({val * 2, cnt + 1});
        }
        if (val * 10 + 1 <= b) {
            q.push({val * 10 + 1, cnt + 1});
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> a >> b;

    sol();

    if (answer == 2e9) {
        cout << -1;
    } else {
        cout << answer + 1;
    }
}
