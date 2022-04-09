#include <iostream>
#include <algorithm>

using namespace std;

int mod=9901;
int d[100001][3];
int dp(int n)
{
    int sum=0;
    d[1][0]=1;
    d[1][1]=1;
    d[1][2]=1;
    for(int i=2; i<n+1; i++)
    {
        d[i][0]=(d[i-1][0]+d[i-1][1]+d[i-1][2])%mod;
        d[i][1]=(d[i-1][0]+d[i-1][2])%mod;
        d[i][2]=(d[i-1][0]+d[i-1][1])%mod;
    }
    sum = (d[n][0]+d[n][1]+d[n][2])%mod;
    return sum;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << dp(n);
}