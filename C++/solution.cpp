#include <iostream>

using namespace std;

int a[1000001];

int dp(int i)
{
    if(i==1)    return 0;
    if(i==2)    return 1;
    if(i==3)    return 1;

    if(i%2==0 && i%3==0)
    {
        if(a[i/3] > a[i/2])
            return a[i/2]+1;
        else
            return a[i/3]+1;
    }
    else if(i%3==0 && i%2!=0)
    {
        if( a[i/3] > a[i-1] )
            return a[i-1]+1;
        else
            return a[i/3]+1;
    }
    else if(i%2==0 && i%3!=0)
    {
        if( a[i/2] > a[i-1] )
            return a[i-1]+1;
        else
            return a[i/2]+1;
    }
    else
        return a[i-1]+1;
}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
    {
        a[i]=dp(i);
    }
    cout << a[n];
}