#include <iostream>

using namespace std;

int d[1001];
int a[1001];
int dp(int n)
{
    int sol=0;
    for(int i=1; i<n+1; i++)
    {
        d[i]=1;
        for(int j=i-1; j>0; j--)
        {
            if(a[i] > a[j])
            {
                if(d[i] < d[j]+1)
                    d[i]=d[j]+1;
            }
        }
        if(sol < d[i])
            sol=d[i];
    }
    return sol;
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
