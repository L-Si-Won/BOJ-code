#include <iostream>

using namespace std;

long long d[91][2];
void dp(int n)
{
    d[1][1]=1;
    for(int i=2; i<n+1; i++)
    {
        d[i][0]+=d[i-1][0];
        d[i][1]+=d[i-1][0];
        d[i][0]+=d[i-1][1];
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    dp(n);
    cout << d[n][0]+d[n][1];
}
