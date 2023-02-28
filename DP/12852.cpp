#include <iostream>

using namespace std;

int n, dp[1000001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    //dp
    for(int i = 1; i <= n; i++)
        dp[i] = i - 1;

    for(int i = 2; i <= n; i++){
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    //output
    cout << dp[n] << "\n";
    while (n != 1){
        cout << n << " ";
        if (dp[n] == dp[n - 1] + 1)
            n -= 1;
        else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1)
            n /= 2;
        else if (n % 3 == 0 && dp[n] == dp[n / 3] + 1)
            n /= 3;
    }
    cout << n;
}
