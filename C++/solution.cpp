#include <iostream>
#include <algorithm>

using namespace std;

int d[1001][2];
int a[1001];
int dp(int n)
{
    d[1][0]=1;
    d[1][1]=1;
    int INC;
    int DEC;
    int MAX;
    for(int i=2; i<n+1; i++)
    {
        INC=1;
        DEC=1;
        for(int j=i-1; j>0; j--)
        {
            if(a[i] > a[j])
                INC=max(INC, d[j][0]+1);
            else if(a[i] < a[j])
                DEC=max(max(d[j][0]+1, d[j][1]+1), DEC);
        }
        d[i][0]=INC;
        d[i][1]=DEC;
    }
    MAX=max(d[1][0], d[1][1]);
    for(int i=2; i<n+1; i++)
        MAX=max(max(MAX, d[i][0]), d[i][1]);
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