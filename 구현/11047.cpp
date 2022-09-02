#include <iostream>
using namespace std;

int main()
{
    int n ,k;
    cin >> n >> k;
    int a[n] = {0};
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int i = n-1;
    int b = 0;
    while(k!=0)
    {
        if(k >= a[i])
        {
            b = b + k/a[i];
            k = k%a[i];
        }
        i--;
    }
    cout << b;
}
