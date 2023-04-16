#include <iostream>

using namespace std;

int n;
string s[50], answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    //compare
    int len = s[0].length();
    for(int i = 0; i < len; i++){
        bool flag = true;

        for(int j = 0; j < n - 1; j++)
            if (s[j][i] != s[j + 1][i])
                flag = false;

        if (flag == true)
            answer += s[0][i];
        else
            answer += '?';
    }

    //output
    cout << answer;
}
