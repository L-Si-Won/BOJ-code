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
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(int i=0; i<n; i++)
        cout << a[i] << "\n";
}