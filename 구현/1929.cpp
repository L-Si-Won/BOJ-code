#include <iostream>

using namespace std;

int m, n;
bool is_not_prime[1000001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> m >> n;

    //check prime number
    is_not_prime[1] = true;
    for(int i = 2; i <= 1000000; i++)
        if (is_not_prime[i] == false)
            for(int j = i * 2; j <= 1000000; j += i)
                is_not_prime[j] = true;

    //output
    for(int i = m; i <= n; i++)
        if (is_not_prime[i] == false)
            cout << i << "\n";
}
