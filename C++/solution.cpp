#include <iostream>

using namespace std;

long long d[1000001];
int mod=1e9+9;

void dp()
{
    d[1]=1;
    d[2]=2;
    d[3]=4;
    for(int i=4; i<1000001; i++)
        d[i]=(d[i-1]+d[i-2]+d[i-3])%mod;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    dp();
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        cout << d[a]%mod << "\n";
    }
}