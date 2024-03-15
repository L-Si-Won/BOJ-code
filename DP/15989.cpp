#include <iostream>

using namespace std;

int t, n, dp[10001][4];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;

    //preprocessing
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= 10000; i++){
        //1+1+...
        dp[i][1] = dp[i - 1][1];

        //2+1+..., 2+2+1+..., ...
        dp[i][2] = dp[i - 2][2] + 1;

        //3+1+..., 3+2+..., 3+3+..., ...
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    //output
    while (t--){
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
}
