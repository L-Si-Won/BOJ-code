#include <iostream>

using namespace std;

int t;
string s;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while (t--){
        cin >> s;

        int sum = 0, score = 0;

        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'O'){
                sum += score + 1;
                score++;
            }
            else
                score = 0;
        }

        cout << sum << "\n";
    }
}
