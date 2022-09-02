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
    string s;
    cin >> s;
    int one=0, zero=0;
    int change=0;
    for(int i=0; i<s.length()-1; i++)
    {
        if(s[i]!=s[i+1])
        {
            change++;
        }
    }
    if(change%2==0)
        cout << change/2;
    else
        cout << change/2 + 1;
}
