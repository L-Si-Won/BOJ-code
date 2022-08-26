#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char, float>>v(n);
    stack<double>stk;
    double temp=0;
    char save='A';
    for(int i=0; i<n; i++)
    {
        v[i].first=save++;
        cin >> v[i].second;
    }
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            for(int j=0; j<26; j++)
            {
                if(v[j].first==s[i])
                {
                    stk.push(v[j].second);
                }
            }
        }
        if(s[i] == '*')
        {
            temp=stk.top();
            stk.pop();
            temp = stk.top() * temp;
            stk.pop();
            stk.push(temp);
        }
        if(s[i] == '/')
        {
            temp=stk.top();
            stk.pop();
            temp = stk.top() / temp;
            stk.pop();
            stk.push(temp);
        }
        if(s[i] == '+')
        {
            temp=stk.top();
            stk.pop();
            temp = stk.top() + temp;
            stk.pop();
            stk.push(temp);
        }
        if(s[i] == '-')
        {
            temp=stk.top();
            stk.pop();
            temp = stk.top() - temp;
            stk.pop();
            stk.push(temp);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << stk.top();
}
