#include <iostream>

using namespace std;
#define max 100001
int d[max];
void dp(int n)
{
    d[1]=1;
    d[2]=2;
    d[3]=3;

    for(int i=4; i<n+1; i++)
    {
        d[i]=d[i-1]+1;
        for(int j=1; j*j<=i; j++)
        {
            if(d[i-j*j]+1 < d[i])
                d[i]=d[i-j*j]+1;
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    dp(n);
    cout << d[n];
}
