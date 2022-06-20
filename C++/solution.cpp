#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coin[101];
int dp[10001];

void solve(){
    for(int i=1; i<=k; i++)
        dp[i]=2e9;

    for(int i=1; i<=n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j]=min(dp[j], dp[j-coin[i]]+1);
        }
    }

    if(dp[k]==2e9) cout << "-1";
    else cout << dp[k];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> coin[i];
    solve();
}