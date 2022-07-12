#include <iostream>

using namespace std;

int n, m, arr[2001], s, e;
int dp[2001][2001];

void solve(){
    for(int i=1; i<=n; i++)
        dp[i][i]=1;
    for(int i=1; i<n; i++)
        if(arr[i]==arr[i+1]) dp[i][i+1]=1;

    for(int i=n-1; i>=1; i--)
        for(int j=i+2; j<=n; j++)
            dp[i][j] = (dp[i+1][j-1]==1 && arr[i]==arr[j]) ? 1 : 0;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    solve();
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}