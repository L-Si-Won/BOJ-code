#include <iostream>
#include <stack>

using namespace std;

void stackprint(stack<char> &stack)
{
    while(!stack.empty())
    {
        cout << stack.top();
        stack.pop();
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    getline(cin, s);
    stack<char>stk;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='<')
        {
            stackprint(stk);
            while(1)
            {
                if(s[i]=='>')
                {
                    cout << '>';
                    break;
                }
                cout << s[i];
                i++;
            }
        }
        else if(s[i]==' ')
        {
            stackprint(stk);
            cout << ' ';
        }
        else
        {
            stk.push(s[i]);
        }
    }
    stackprint(stk);
}
