#include <iostream>
#include <algorithm>

using namespace std;

int d[100001][3];
int a[3][100001];
int dp(int n)
{
    int ans;
    d[1][0]=0;
    d[1][1]=a[1][1];
    d[1][2]=a[2][1];
    for(int i=2; i<n+1; i++)
    {
        d[i][0]=max(max(d[i-1][0], d[i-1][1]), d[i-1][2]);
        d[i][1]=max(d[i-1][0], d[i-1][2])+a[1][i];
        d[i][2]=max(d[i-1][0], d[i-1][1])+a[2][i];
    }
    ans = max(max(d[n][0], d[n][1]), d[n][2]);
    return ans;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;
    int n;
    for(int i=0; i<test_case; i++)
    {
        cin >> n;
        for(int j=1; j<n+1; j++)
            cin >> a[1][j];
        for(int j=1; j<n+1; j++)
            cin >> a[2][j];
        cout << dp(n) << "\n";
    }
}
