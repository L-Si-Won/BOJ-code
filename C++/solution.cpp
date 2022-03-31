#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int>a(26, -1);
    
    for(int i=0; i<s.size(); i++)
    {
        if(a[s[i]-97] == -1)
        {
            a[s[i]-97]=i;
        }
    }
    for(int i=0; i<26; i++)
        cout << a[i] << " ";
}