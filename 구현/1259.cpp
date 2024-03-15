#include <iostream>

using namespace std;

string s;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1){
        cin >> s;

        if (s == "0")
            break;

        bool flag = true;
        for (int i = 0; i < s.length() / 2; i++)
            if (s[i] != s[s.length() - i - 1])
                flag = false;

        if (flag == true)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
