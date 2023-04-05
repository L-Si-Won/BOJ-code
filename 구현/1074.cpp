#include <iostream>
#include <cmath>

using namespace std;

int n, r, c, answer;

void solve(){
    for(int i = n; i > 0; i--){
        int half = pow(2, i - 1);

        if (r >= half){
            answer += half * half * 2;
            r -= half;
        }
        if (c >= half){
            answer += half * half;
            c -= half;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> r >> c;

    //solve
    solve();

    //output
    cout << answer;
}
