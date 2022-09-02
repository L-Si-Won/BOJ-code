#include <iostream>

using namespace std;

int n;
int dp[50];

void fibo(){
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-2]+dp[i-1];
    }
    cout << dp[n];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    fibo();
}
