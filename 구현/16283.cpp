#include <iostream>

using namespace std;

int a, b, n, w;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> a >> b >> n >> w;

    //brute force
    int x, y, answer_cnt = 0;

    for (int i = 1; i <= n - 1; i++){
        if (a * i + b * (n - i) == w){
            answer_cnt++;
            x = i;
            y = n - i;
        }
    }

    //output
    if (answer_cnt == 1)
        cout << x << " " << y;
    else
        cout << -1;
}
