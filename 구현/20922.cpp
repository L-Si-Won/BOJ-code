#include <iostream>

using namespace std;

int n, k, arr[200000], cnt[100001];
int s, e, answer;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cnt[arr[e]]++;
    while (e < n && s <= e) {
        e++;
        cnt[arr[e]]++;
        
        if (cnt[arr[e]] > k) {
            answer = max(answer, (e - 1) - s + 1);

            for (int i = s; i < e; i++) {
                cnt[arr[i]]--;

                if (arr[i] == arr[e]) {
                    s = i + 1;
                    break;
                }
            }
        }
    }

    if (cnt[arr[e - 1]] <= k) {
        answer = max(answer, (e - 1) - s + 1);
    }

    cout << answer;
}
