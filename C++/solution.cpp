#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int  n;
    cin >> n;
    long long len[n-1];
    for(int i=0; i<n-1; i++)
        cin >> len[i];
    long long prc[n];
    for(int i=0; i<n; i++)
        cin >> prc[i];

    int sum=0;
    int temp_prc=prc[0];
    for(int i=0; i<n-1; i++)
    {
        if(temp_prc > prc[i])
        {
            temp_prc=prc[i];
        }
        sum += temp_prc*len[i];
    }
    cout << sum;
}