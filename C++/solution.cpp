#include <iostream>

using namespace std;

long long d[101][11];
int mod=1e9;

void stair(int n)
{
    for(int i=1; i<10; i++)
        d[1][i]=1;
    for(int i=2; i<n+1; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j==0)
                d[i][j]=d[i-1][j+1]%mod;
            if(j==9)
                d[i][j]=d[i-1][j-1]%mod;
            else
                d[i][j]=(d[i-1][j-1]+d[i-1][j+1])%mod;
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    stair(n);
    long long sum=0;
    for(int i=0; i<10; i++)
        sum+=d[n][i]%mod;
    cout << sum%mod;
}