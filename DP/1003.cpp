#include <iostream>

using namespace std;

int t, n;
pair<int, int> dp[41];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //fibonacci sequence
    dp[0].first = 1;
    dp[1].second = 1;
    for(int i = 2; i < 41; i++){
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }

    //input
    cin >> t;
    while(t--){
        cin >> n;

        //output
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
}
