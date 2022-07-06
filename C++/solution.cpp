#include <iostream>
#include <algorithm>

using namespace std;

int t, k, arr[501];
int dp[501][501], sum[501];

void solve(){
    for(int i=1; i<k+1; i++)
        sum[i]=sum[i-1]+arr[i];

    for(int i=1; i<k+1; i++){
        for(int j=1; j<=k-i; j++){
            dp[j][i+j]=2e9;
            for(int l=j; l<i+j; l++)
                dp[j][i+j]=min(dp[j][i+j], dp[j][l]+dp[l+1][i+j]+sum[i+j]-sum[j-1]);
        }
    }
    cout << dp[1][k] << "\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> k;
        for(int i=1; i<k+1; i++)
            cin >> arr[i];
        solve();
    }
}