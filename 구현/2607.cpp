#include <iostream>

using namespace std;

int n, c[100][26], answer;
string s[100];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> s[i];

        for (int j = 0; j < s[i].length(); j++)
            c[i][s[i][j] - 'A']++;

        if (i == 0)
            continue;

        int same = 0;
        for (int j = 0; j < 26; j++)
            same += c[0][j] > c[i][j] ? c[i][j] : c[0][j];

        int temp = answer;
        if (s[0].length() == s[i].length()){
            if (same == s[0].length() || same == s[0].length() - 1)
                answer++;
        }
        else if (s[0].length() - 1 == s[i].length()){
            if (same == s[0].length() - 1)
                answer++;
        }
        else if (s[0].length() + 1 == s[i].length()){
            if (same == s[0].length())
                answer++;
        }
    }

    cout << answer;
}
