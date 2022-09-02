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
    
    int n=0;
    cin >> n;
    string s[n];
    for(int i=0; i<n; i++)
        cin >> s[i];

    int open=0;
    int j=0;
    for(int i=0; i<n; i++)
    {
        open=0;
        j=0;
        int len=s[i].length();
        while(len--)
        { 
            if(open == 0)
            {
                if(s[i][j]==')')
                {
                    cout << "NO\n";
                    goto skip;
                }
                if(s[i][j]=='(')
                {
                    open++;
                    j++;
                }
            }
            else if(open >= 1)
            {
                if(s[i][j]=='(')
                {
                    open++;
                    j++;
                }
                else
                {
                    open--;
                    j++;
                }
            }
        }
        if(open==0)
            cout << "YES\n";
        else
            cout << "NO\n";
    skip:
        j=0;
    }
}
