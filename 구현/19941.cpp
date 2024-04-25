#include <iostream>

using namespace std;

int n, k, answer;
string s;
bool eat[20100];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k >> s;

    s = "0000000000" + s + "0000000000";

    for (int i = 10; i < n + 10; i++){
        if (s[i] == 'P'){
            for (int j = i - k; j <= i + k; j++){
                if (s[j] == 'H' && eat[j] == false){
                    eat[j] = true;
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer;
}
