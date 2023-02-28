#include <iostream>

using namespace std;

int n, num, cnt;
bool is_not_prime[1001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //check prime number
    is_not_prime[1] = true;
    for (int i = 2; i < 1001; i++)
        if (is_not_prime[i] == false)
            for(int j = i * 2; j < 1001; j += i)
                is_not_prime[j] = true;

    //input and count prime number
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        if (is_not_prime[num] == false)
            cnt++;
    }

    //output
    cout << cnt;
}
