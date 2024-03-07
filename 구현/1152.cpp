#include <iostream>
#include <string>

using namespace std;

string s;
int cnt;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    getline(cin, s);
    
    for (int i = 0; i < s.length(); i++){
        if (i == 0 && s[i] != ' ')
            cnt++;
        else if (s[i - 1] == ' ' && s[i] != ' ')
            cnt++;
    }

    cout << cnt;
}
