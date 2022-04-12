#include <iostream>

using namespace std;

int d[31];
int dp(int n)
{
    d[2] = 3;
    d[4] = 11;
    d[6] = 41;
    for (int i = 8; i < n + 1; i++)
    {
        if (i % 2 == 0)
        {
            d[i] = d[i - 2] * 3;
            for (int j = i - 4; j >= 0; j--)
                d[i] += d[j] * 2;
            d[i]+=2;
        }
    }
    return d[n];
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << dp(n);
}