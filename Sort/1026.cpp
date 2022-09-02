#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i=0; i<n; i++) 
        cin >> a[i];
    for(int i=0; i<n; i++) 
        cin >> b[i];
 
    int bcp[n]={0}; // b의 오름차순배열
    for(int i=0; i<n; i++)
        bcp[i]=b[i];
    sort(bcp, bcp+n);

    sort(a, a+n, cmp);

    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum = sum + (a[i]*bcp[i]);
    }
    cout << sum;
}
