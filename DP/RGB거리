#include <iostream>
#include <algorithm>

using namespace std;

int d[1001][3];
int c[1001][3];

void dp(int n)
{
    for(int i=1; i<n+1; i++)
    {
        d[i][0]=min(d[i-1][1],d[i-1][2])+c[i][0];
        d[i][1]=min(d[i-1][2],d[i-1][0])+c[i][1];
        d[i][2]=min(d[i-1][0],d[i-1][1])+c[i][2];
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
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    dp(n);
    cout << min(min(d[n][0], d[n][1]),d[n][2]);
}
