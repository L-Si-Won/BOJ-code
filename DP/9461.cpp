#include <iostream>

using namespace std;

int t, n;
long long int dp[101];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;

    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}
