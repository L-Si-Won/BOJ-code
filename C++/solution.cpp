#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int a=0, b=0, c=0, d=0;
        for(int j=0; j<s.size(); j++)
        {
            if(s[j]>='a' && s[j]<='z')
                a++;
            if(s[j]>='A' && s[j]<='Z')
                b++;
            if(s[j]==' ')
                d++;
            if(s[j]>='0' && s[j]<='9')
                c++;
        }
        cout << a << " " << b << " " << c << " " << d << '\n';
    }
}