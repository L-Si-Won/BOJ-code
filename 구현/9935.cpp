#include <iostream>

using namespace std;

string s, boom;
char res[1'000'001];
int idx;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s >> boom;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != boom[boom.length() - 1]) {
            res[idx++] = s[i];
        } else {
            if (idx >= boom.length() - 1) {
                bool flag = true;

                for (int j = 0; j < boom.length() - 1; j++) {
                    if (res[idx - boom.length() + 1 + j] != boom[j]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    idx = idx - boom.length() + 1;
                } else {
                    res[idx++] = s[i];
                }
            } else {
                res[idx++] = s[i];
            }
        }
    }

    res[idx] = '\0';

    if (idx == 0) {
        cout << "FRULA";
    } else {
        cout << res;
    }
}
