#include <iostream>
#include <algorithm>

using namespace std;

long long n, dp[91];

void fibo(){
    dp[1]=1;
    for(int i=2; i<=n; i++)
        dp[i]=dp[i-1]+dp[i-2];
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    fibo();
    cout << dp[n];
}