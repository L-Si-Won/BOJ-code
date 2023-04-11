#include <iostream>

using namespace std;

int t, a, b;

int power(int a, int b){
    if (a == 1)
        return 1;
    if (b == 1)
        return a % 10;
    
    int half = power(a, b / 2) % 10;

    if (b % 2 == 0)
        return half * half % 10;
    else
        return half * half % 10 * a % 10;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> t;

    while(t--){
        cin >> a >> b;

        //calculate a^b
        int answer = power(a, b);

        //output
        if (answer == 0)
            cout << 10 << "\n";
        else
            cout << answer << "\n";
    }
}
