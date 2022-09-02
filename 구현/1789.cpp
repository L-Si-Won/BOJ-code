#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long s=0;
    cin >> s;
    long long sum=0;
    long n=1;
    int cnt=0;

    while(1)
    {
        if(s < sum)
            break;
        sum = (n*(n+1)) / 2;
        n++;
        cnt++;
    }
    cout << cnt-1;

}
