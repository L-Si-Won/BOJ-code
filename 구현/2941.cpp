#include <iostream>

using namespace std;

string s;
string croa[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        bool flag2 = false;
        for (int j = 0; j < 8; j++) {
            bool flag = true;
            for (int k = 0; k < croa[j].length(); k++) {
                if (croa[j][k] != s[i + k]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                flag2 = true;
                i += croa[j].length() - 1;
                answer++;
                break;
            }
        }

        if (!flag2) {
            answer++;
        }
    }

    cout << answer;
}
