#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>v;
    int a;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    vector<int>temp;
    for(int i=0; i<n; i++)
    {
        temp.push_back((n-i) * v[i]);
    }
    int max=temp[0];
    for(int i=1; i<n; i++)
    {
        if(max < temp[i])
            max = temp[i];
    }
    cout << max;
}