#include <iostream>

using namespace std;

int n, sum;
char c;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    while (n--){
        cin >> c;
        sum += c - '0';
    }

    cout << sum;
}
