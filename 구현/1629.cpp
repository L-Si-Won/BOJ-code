#include <iostream>

using namespace std;

int a, b, c, answer = 1;

long long func(int power){
    if (power == 1)
        return a % c;

    long long half = func(power / 2) % c;

    if (power % 2 == 0)
        return half * half % c;
    else
        return half * half % c * a % c;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> a >> b >> c;
    
    //calculate and output
    cout << func(b);
}
