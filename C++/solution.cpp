#include <iostream>
#include <algorithm>

using namespace std;

int d[501][501];
int a[501][501];
int dp(int n)
{
    d[1][1]=a[1][1];
    for(int i=2; i<n+1; i++)
        for(int j=1; j<i+1; j++)
            d[i][j]=max(d[i-1][j], d[i-1][j-1])+a[i][j];
    int MAX=d[n][1];
    for(int i=2; i<n+1; i++)
        MAX=max(MAX, d[n][i]);
    return MAX;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<i+1; j++)
            cin >> a[i][j];
    cout << dp(n);   
}