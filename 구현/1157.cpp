#include <iostream>

using namespace std;

string s;
int alpha[26], Max, dup;
char answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    for (int i = 0; i < s.length(); i++){
        if (s[i] <= 'Z' && s[i] >= 'A')
            alpha[s[i] - 'A']++;
        else
            alpha[s[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++){
        if (alpha[i] > Max){
            Max = alpha[i];
            answer = 'A' + i;
            dup = 0;
        }
        else if (alpha[i] == Max)
            dup = 1;
    }

    if (dup == 0)
        cout << answer;
    else
        cout << "?";
}
