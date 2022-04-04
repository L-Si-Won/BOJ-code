#include <iostream>
#include <vector>

using namespace std;

int d[1001];
int a[1001];

int dp(int x)
{
    for(int i=1; i<x+1; i++)
        d[i]=a[i];

    for(int i=2; i<x+1; i++)
    {
        for(int j=1; j<i+1; j++)
        {
            if(d[i] > a[j]+d[i-j])
                d[i] = a[j]+d[i-j];
        }
    }
    return d[x];
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