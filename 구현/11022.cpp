#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, x;
    cin >> x;
    for (int i = 1; i <= x; i++){
        cin >> a >> b;
        cout << "Case #";
        cout << i;
        cout << ": ";
        cout << a;
        cout << " + ";
        cout << b;
        cout << " = ";
        cout << a + b << "\n";
    }
}
