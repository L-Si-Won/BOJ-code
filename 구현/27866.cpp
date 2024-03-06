#include <iostream>

using namespace std;

int i;
string s;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s >> i;
    cout << s[i - 1];
}
