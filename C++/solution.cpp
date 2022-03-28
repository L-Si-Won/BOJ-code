#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    bool minus=false;
    string temp="";
    int sum=0;

    for(int i=0; i<s.length()+1; i++)
    {
        if(s[i]=='-' || s[i]=='+' || s[i]=='\0')
        {
            if(minus)
                sum -= stoi(temp);
            else
                sum += stoi(temp);
            temp="";
            if(s[i]=='-')
                minus=true;
        }
        else
            temp+=s[i];
    }
    cout << sum;
}