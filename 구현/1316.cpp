#include <iostream>
#include <string.h>

using namespace std;

int n, answer;
string s;
bool used[26], flag;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    while (n--) {
        cin >> s;

        memset(used, false, sizeof(used));
        flag = true;

        for (int i = 0; i < s.length(); i++) {
            if (i == 0) {
                used[s[i] - 'a'] = true;
            }
            else {
                if (s[i] != s[i - 1]) {
                    if (used[s[i] - 'a'] == true) {
                        flag = false;
                        break;
                    } else {
                        used[s[i] - 'a'] = true;
                    }
                }
            }
        }

        if (flag == true) {
            answer++;
        }
    }

    cout << answer;
}
