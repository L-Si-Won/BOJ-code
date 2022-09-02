#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>f(1000001, 0);
    stack<int>stk;
    vector<int>ngf(n,-1);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        f[a[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        while( !stk.empty() && f[a[stk.top()]] < f[a[i]] )
        {
            ngf[stk.top()]=a[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i=0; i<n; i++)
        cout << ngf[i] << " ";
}
