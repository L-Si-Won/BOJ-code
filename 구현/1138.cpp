#include <iostream>

using namespace std;

int n, arr[11], ans[11];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    ans[arr[1] + 1] = 1;
    for (int i = 2; i <= n; i++) {
        int cnt = 0;

        for (int j = 1; j <= n; j++) {
            if (ans[j] == 0 && cnt == arr[i]) {
                ans[j] = i;
                break;
            }
            if (ans[j] == 0) {
                cnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}
