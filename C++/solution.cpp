#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int n;
    cin >> n;
    list<char>list(s.begin(), s.end());
    auto now = list.end();

    while(n--)
    {
        char cmd;
        cin >> cmd;

        if(cmd == 'L')
        {
            if(now != list.begin())
                now--;
        }
        if(cmd == 'D')
        {
            if(now != list.end())
                now++;
        }
        if(cmd == 'B')
        {
            if(now != list.begin())
            {
                now=list.erase(--now);
            }
        }
        if(cmd == 'P')
        {
            char opr;
            cin >> opr;
            list.insert(now, opr);
        }
    }
    for(auto i=list.begin(); i!=list.end(); i++)
        cout << *i;
}