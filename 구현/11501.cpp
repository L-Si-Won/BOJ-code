#include <iostream>

using namespace std;

int t, n, price[1000000], day[1000000];
long long answer;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> price[i];
        }

        day[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (price[i] > price[day[i + 1]]) {
                day[i] = i;
            } else {
                day[i] = day[i + 1];
            }
        }

        answer = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (price[i] < price[day[i]]) {
                answer += price[day[i]] - price[i];
            }
        }

        cout << answer << "\n";
    }
}
