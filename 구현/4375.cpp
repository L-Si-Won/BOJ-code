#include <iostream>

using namespace std;

int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (cin >> n){
        long long num = 1;
        int cnt = 1;

        while (1){
            if (num % n == 0)
                break;
            num %= n;
            num = num * 10 + 1;
            cnt++;
        }

        cout << cnt << "\n";
    }
}
