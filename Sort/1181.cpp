#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s[20000];

bool cmp(string a, string b) {
    if (a.length() < b.length()) {
        return true;
    } else if (a.length() > b.length()) {
        return false;
    } else {
        if (a < b) {
            return true;
        } else {
            return false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    sort(s, s + n, cmp);

    cout << s[0];
    for (int i = 1; i < n; i++) {
        if (s[i].compare(s[i - 1]) != 0) {
            cout << "\n" << s[i];
        }
    }
}
