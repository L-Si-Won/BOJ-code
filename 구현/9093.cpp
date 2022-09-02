#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s;
    string temp;
    cin.ignore();

    for(int i=0; i<n; i++)
    {
        getline(cin, s);
        stringstream sstream(s);
        while(sstream >> temp)
        {
            reverse(temp.begin(), temp.end());
            cout << temp << " ";
        }
        cout << "\n";
    }
}
