#include <iostream>

using namespace std;

int n;
int arr[101][101];
long long dp[101][101];

void solve(){
    dp[1][1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j]!=0 && i<=n && j<=n){
                int val=arr[i][j];
                int down=i+val;
                int right=j+val;
                if(down<=n)
                    dp[down][j]+=dp[i][j];
                if(right<=n)
                    dp[i][right]+=dp[i][j];
            }
        }
    }
    cout << dp[n][n];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> arr[i][j];
    solve();
}