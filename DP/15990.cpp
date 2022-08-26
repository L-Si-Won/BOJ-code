#include <iostream>

using namespace std;

long long d[100001][4];
int mod=1e9 + 9;

void dp()
{
    d[1][1]=1;
    d[2][2]=1;
    d[3][1]=1, d[3][2]=1, d[3][3]=1;
    for(int i=4; i<100001; i++)
    {
        d[i][1]=(d[i-1][2]+d[i-1][3])%mod;
        d[i][2]=(d[i-2][1]+d[i-2][3])%mod;
        d[i][3]=(d[i-3][1]+d[i-3][2])%mod;
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test;
    cin >> test;
    int n;
    dp();
    for(int i=0; i<test; i++)
    {
        cin >> n;
        cout << (d[n][1]+d[n][2]+d[n][3])%mod << "\n";
    }
}
