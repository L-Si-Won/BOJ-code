#include <iostream>

using namespace std;

int n, m, avg, arr[1000000];
int up, down;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m += arr[i];
    }

    avg = m / n;

    for (int i = 0; i < n; i++) {
        if (arr[i] < avg) {
            up += avg - arr[i];
        } else if (arr[i] > avg + 1) {
            down += arr[i] - (avg + 1);
        }
    }

    if (up > down) {
        cout << up;
    } else {
        cout << down;
    }
}
