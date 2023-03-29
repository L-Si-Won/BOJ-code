#include <iostream>

using namespace std;

long long n;
long long answer = 1;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    //Euler's totient function
    for(int i = 2; i <= n / i; i++){
        if (n % i == 0){
            answer *= i - 1;

            while (n % i == 0){
                answer *= i;
                n /= i;
            }
            answer /= i;
        }
    }

    if (n != 1)
        answer = answer * (n - 1);

    //output
    cout << answer;
}
