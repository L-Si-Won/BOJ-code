#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, arr[1501][1501];
priority_queue<int, vector<int>, greater<int>> q;

bool cmp(short a, short b) {
    return a > b ? true : false;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (q.size() < n) {
                q.push(arr[i][j]);
            } else {
                int temp = q.top();

                if (arr[i][j] > temp) {
                    q.pop();
                    q.push(arr[i][j]);
                }
            }
        }
    }

    cout << q.top();
}
