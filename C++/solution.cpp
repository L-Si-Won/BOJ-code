#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int>stk;
    int nge[n];
    for(int i=0; i<n; i++)
        nge[i]=-1;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        while(!stk.empty() && a[stk.top()] < a[i])
        {
            nge[stk.top()]=a[i];
            stk.pop();
        }
        stk.push(i);
    }
    for(int i=0; i<n; i++)
        cout << nge[i] << " ";
}