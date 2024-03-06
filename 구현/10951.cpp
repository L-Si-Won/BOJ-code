#include <iostream>

using namespace std;

int a, b;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (cin >> a >> b){
        cout << a + b << "\n";
    }
}
