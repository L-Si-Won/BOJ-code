#include <iostream>
#include <stack>

using namespace std;



int main()
{
    string s;
    cin >> s;
    int open=0;
    int sum=0;
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i]=='(' && s[i+1]=='(')
        {
            open++;
        }
        else if(s[i]=='(' && s[i+1]==')')
        {
            sum += open;
        }
        else if(s[i]==')' && s[i+1]==')')
        {
            sum += 1;
            open--;
        }
    }
    cout << sum;
}
