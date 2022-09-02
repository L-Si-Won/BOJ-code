#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int>a(26, 0);
    for(int i=0; i<s.size(); i++)
    {
        a[s[i]-97]++;
    }
    for(int i=0; i<26; i++)
        cout << a[i] << " ";
}
