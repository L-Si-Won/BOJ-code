#include <iostream>

using namespace std;

int n, sum;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 5; i++){
        cin >> n;
        sum += n * n;
    }
    
    cout << sum % 10;
}
