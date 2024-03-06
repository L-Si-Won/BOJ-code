#include <iostream>

using namespace std;

int t, r;
string s;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (t--){
        cin >> r >> s;

        for (int i = 0; i < s.length(); i++)
            for (int j = 0; j < r; j++)
                cout << s[i];
        cout << "\n";
    }
}
