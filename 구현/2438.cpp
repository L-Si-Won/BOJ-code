#include <iostream>

using namespace std;

int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << "\n";
    }
}
