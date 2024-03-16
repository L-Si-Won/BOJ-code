#include <iostream>

using namespace std;

bool is_vowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1){
        string s;
        bool flag1 = false, flag2 = true, flag3 = true;

        cin >> s;

        if (s == "end")
            break;

        for (int i = 0; i < s.length(); i++){
            //first rule
            if (is_vowel(s[i]))
                flag1 = true;

            //second rule
            if (i >= 2){
                if (is_vowel(s[i - 2]) && is_vowel(s[i - 1]) && is_vowel(s[i]))
                    flag2 = false;
                if (!is_vowel(s[i - 2]) && !is_vowel(s[i - 1]) && !is_vowel(s[i]))
                    flag2 = false;
            }

            //third rule
            if (i >= 1)
                if (s[i] != 'e' && s[i] != 'o')
                    if (s[i] == s[i - 1])
                        flag3 = false;
        }

        //output
        cout << "<" << s << "> is ";
        if (flag1 && flag2 && flag3)
            cout << "acceptable.\n";
        else
            cout << "not acceptable.\n";
    }
}
