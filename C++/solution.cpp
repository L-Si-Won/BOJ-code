#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    char temp[s.size()];
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='a' && s[i]<='m')
        {
            temp[i]=s[i]+13;
        }
        else if(s[i]>='n' && s[i]<='z')
        {
            temp[i]='a'+s[i]-110;
        }
        else if(s[i]>='A' && s[i]<='M')
        {
            temp[i]=s[i]+13;
        }
        else if(s[i]>='N' && s[i]<='Z')
        {
            temp[i]='A'+s[i]-78;
        }
        else
            temp[i]=s[i];
    }
    for(int i=0; i<s.size(); i++)
        cout << temp[i];
}