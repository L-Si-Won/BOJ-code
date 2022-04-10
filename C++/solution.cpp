#include <iostream>
#include <algorithm>

using namespace std;

int d[10001][3];
int a[10001];
int dp(int n)
{
    int ans;
    int three=1;
    d[1][0]=0;
    d[1][1]=a[1];
    d[1][2]=a[1];
    for(int i=2; i<n+1; i++)
    {
        d[i][0]=max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
        d[i][1]=d[i-1][0]+a[i];
        d[i][2]=d[i-1][1]+a[i];
    }
    ans = max(max(d[n][0], d[n][1]),d[n][2]);
    return ans;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<n+1; i++)
        cin >> a[i];
    cout << dp(n);
}