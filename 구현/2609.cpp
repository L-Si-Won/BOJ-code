#include <iostream>

using namespace std;

int GCD(int a, int b){
    if (a < b){
        int temp = a;
        a = b;
        b = temp;
    }
    int gcd;

    while (1){
        gcd = a % b;
        
        if (gcd == 0)
            return b;
        a = b;
        b = gcd;
    }
}

int LCM(int a, int b, int gcd){
    return a * b / gcd;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    int a, b;
    cin >> a >> b;

    //GCD
    cout << GCD(a, b) << "\n";

    //LCM
    cout << LCM(a, b, GCD(a, b)); 
}
