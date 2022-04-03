#include <iostream>

using namespace std;

int d[1001];

int dp(int i)
{
    if(i==1) return 1;
    if(i==2) return 3;
    if(d[i]!=0) return d[i];
    return d[i]=(dp(i-1)+dp(i-2)*2)%10007;
}

int main()
{
    int n;
    cin >> n;

    cout << dp(n);
}