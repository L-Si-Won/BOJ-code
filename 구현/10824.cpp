#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    long long A, B;
    A=stoll(a+b);
    B=stoll(c+d);
    cout << A+B;
}
