#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string temp;
    vector<string>v;
    for(int i=0; i < s.size(); i++)
    {
        temp = s;
        v.push_back(temp.erase(0,i));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
        cout << v[i] << "\n";
}
