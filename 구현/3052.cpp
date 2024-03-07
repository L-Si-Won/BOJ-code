#include <iostream>

using namespace std;

int mod[42], n, answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 10; i++){
        cin >> n;
        mod[n % 42]++;
    }

    for (int i = 0; i < 42; i++)
        if (mod[i] != 0)
            answer++;
    cout << answer;
}
