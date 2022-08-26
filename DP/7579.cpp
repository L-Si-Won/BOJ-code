#include <iostream>

using namespace std;

int n, m, sum;
int mem[101], cost[101];
int dp[101][10001];

void solve(){
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j>=cost[i]) dp[i][j]=mem[i]+dp[i-1][j-cost[i]];
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
        }
    }
    for(int i=1; i<=sum; i++){
        if(dp[n][i]>=m){
            cout << i;
            break;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> mem[i];
    for(int i=1; i<=n; i++){
        cin >> cost[i];
        sum+=cost[i];
    }
    solve();
}
