#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int a[1001];
int dp(int n)
{
    d[1]=1;
    int MIN;
    for(int i=2; i<n+1; i++)
    {
        MIN=1;
        for(int j=i-1; j>0; j--)
            if(a[i] < a[j])
                MIN=max(MIN, d[j]+1);
        d[i]=MIN;
    }
    MIN=d[1];
    for(int i=2; i<n+1; i++)
        MIN=max(MIN, d[i]);
    return MIN;
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
