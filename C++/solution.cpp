#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v; //행, 열
int dp[501][501];

void solve(){
    for(int i=1; i<n; i++){
        for(int j=1; j<=n-i; j++){
            dp[j][i+j]=2147483647; //INT_MAX도 가능
            for(int k=j; k<=i+j; k++)
                dp[j][i+j]=min(dp[j][i+j], dp[j][k]+dp[k+1][i+j]+(v[j].first*v[k].second*v[i+j].second));
        }
    }
    cout << dp[1][n];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    v.push_back({0, 0});
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    solve();
}