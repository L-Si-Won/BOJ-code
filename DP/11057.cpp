#include <iostream>

using namespace std;

int mod=10007;
int d[1001][10];
int dp(int n)
{
    for(int i=0; i<10; i++)
        d[1][i]=1;
    for(int i=2; i<n+1; i++)
    {
        for(int j=0; j<10; j++)
        {
            int k=j;
            while(k!=-1)
            {
                d[i][j]=(d[i][j]+d[i-1][k])%mod;
                k--;
            }
        }
    }
    int sum=0;
    for(int i=0; i<10; i++)
        sum = (sum+d[n][i])%mod;
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
