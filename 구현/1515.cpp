#include <iostream>
#include <string>

using namespace std;

string s;
int num = 1, idx;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> s;

    while (1){
        string nums = to_string(num);

        for (int i = 0; i < nums.length(); i++){
            if (s[idx] == nums[i])
                idx++;
            if (idx == s.length()){
                cout << num;
                return 0;
            }
        }

        num++;
    }
}
