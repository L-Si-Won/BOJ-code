#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<char>stk;
    vector<char>v;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            v.push_back(s[i]);
        }
        else if(s[i]=='(')
        {
            stk.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!stk.empty() && stk.top()!='(')
            {
                v.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else if(s[i]=='+' || s[i]=='-')
        {
            while(!stk.empty() && stk.top()!='(')
            {
                v.push_back(stk.top());
                stk.pop();
            }
            stk.push(s[i]);
        }
        else if(s[i]=='*' || s[i]=='/')
        {
            while(!stk.empty() && (stk.top()=='/' || stk.top()=='*'))
            {
                v.push_back(stk.top());
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while(!stk.empty())
    {
        v.push_back(stk.top());
        stk.pop();
    }
    for(int i=0; i<v.size(); i++)
        cout << v[i]; 
}
