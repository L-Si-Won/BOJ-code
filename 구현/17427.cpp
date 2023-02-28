#include <iostream>

using namespace std;

int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    //calculate
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (n / i) * i;
    }

    //output
    cout << sum;
}
