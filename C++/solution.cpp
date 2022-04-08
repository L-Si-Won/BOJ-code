#include <iostream>
#include <algorithm>

using namespace std;

int d[1001][3];
int c[1001][3];
int dd[9];

int dp(int n)
{
    int mini = 987654321;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (j == i)
                d[1][i] = c[1][i];
            else
                d[1][i] = 987654321;
        }
        for (int i = 2; i < n + 1; i++)
        {
            d[i][0] = min(d[i - 1][1], d[i - 1][2]) + c[i][0];
            d[i][1] = min(d[i - 1][2], d[i - 1][0]) + c[i][1];
            d[i][2] = min(d[i - 1][0], d[i - 1][1]) + c[i][2];
        }
        for (int i = 0; i < 3; i++)
            if (j != i)
                mini = min(mini, d[n][i]);
    }
    return mini;
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
        cin >> c[i][0] >> c[i][1] >> c[i][2];
    cout << dp(n);
}