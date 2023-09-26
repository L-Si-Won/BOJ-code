#include <iostream>

using namespace std;

int n, s[15];
long long W;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> W;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    //simulation
    long long coin = 0;

    for (int i = 0; i < n; i++){

        if (i == n - 1){ //last day
            W += coin * s[i];
            continue;
        }

        if (s[i] < s[i + 1]){
            long long buy = W / s[i];
            coin += buy;
            W -= buy * s[i];
        }
        else if (s[i] > s[i + 1]){
            W += coin * s[i];
            coin = 0;
        }
    }

    //output
    cout << W;
}
