#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int a[1001];

int dp(int n)
{
    d[1]=a[1];
    int MAX;
    for(int i=2; i<n+1; i++)
    {
        MAX=a[i];
        for(int j=i-1; j>0; j--)
        {
            if(a[i] > a[j])
            {
                MAX=max(MAX, d[j]+a[i]);
            }
        }
        d[i]=MAX;
    }
    MAX=d[1];
    for(int i=2; i<n+1; i++)
        MAX=max(MAX, d[i]);
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
        cin >> a[i];
    cout << dp(n);   
}
