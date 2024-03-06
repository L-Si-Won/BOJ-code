#include <iostream>

using namespace std;

int a, b;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1){
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << a + b << "\n";
    }
}
