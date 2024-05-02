#include <iostream>

using namespace std;

string s, answer;
int cnt0, cnt1;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '0')
            cnt0++;
        if (s[i] == '1')
            cnt1++;
    }
    cnt0 /= 2;
    cnt1 /= 2;

    int idx = s.length() - 1;
    while (1){
        if (cnt0 == 0 || idx < 0)
            break;
        if (cnt0 > 0 && s[idx] == '0'){
            s.erase(idx, 1);
            cnt0--;
        }
        idx--;
    }

    idx = 0;
    while (1){
        if (cnt1 == 0 || idx == s.length())
            break;
        if (cnt1 > 0 && s[idx] == '1'){
            s.erase(idx, 1);
            idx--;
            cnt1--;
        }
        idx++;
    }

    cout << s;
}
