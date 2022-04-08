#include <iostream>

using namespace std;

int mod = 1e9;
long long d[201][201];
void dp()
{
    for(int i=0; i<201; i++)
    {
        d[1][i]=1;
        d[i][1]=i;
        d[i][0]=1;
    }
    d[0][0]=0;
    for(int i=2; i<201; i++)
    {
        for(int j=2; j<201; j++)
        {
            d[i][j]=(d[i][j-1]+d[i-1][j])%mod;
        }
    }
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    dp();
    cout << d[k][n];
}