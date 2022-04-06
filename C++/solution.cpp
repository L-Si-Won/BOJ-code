#include <iostream>

using namespace std;

int d[100001];
int a[100001];
void dp(int n)
{
    d[1]=a[1];
    for(int i=2; i<n+1; i++)
    {
        d[i]=a[i];
        if(d[i] < d[i-1]+a[i])
            d[i]=d[i-1]+a[i];
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
    int max=d[1];
    for(int i=2; i<n+1; i++)
        if(max < d[i])
            max=d[i];
    cout << max;
}