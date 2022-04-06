#include <iostream>
#include <algorithm>

using namespace std;

int d[100001][2];
int a[100001];
void dp(int n)
{
    d[1][0]=a[1];
    d[1][1]=a[1];
    int sol=a[1];
    for(int i=2; i<n+1; i++)
    {
        d[i][0]=a[i];
        if(d[i][0] < d[i-1][0]+a[i])
            d[i][0]=d[i-1][0]+a[i];
        if(d[i-1][0] < a[i]+d[i-1][1])
            d[i][1]=a[i]+d[i-1][1];
        else
            d[i][1]=d[i-1][0];
    }
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
    dp(n);
    int max0=d[1][0];
    for(int i=2; i<n+1; i++)
        if(max0 < d[i][0])
            max0=d[i][0];
    int max1=d[1][1];
    for(int i=2; i<n+1; i++)
        if(max1 < d[i][1])
            max1=d[i][1];
    cout << max(max0, max1);
}