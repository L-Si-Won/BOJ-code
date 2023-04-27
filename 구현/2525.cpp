#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    b += c;
    a += b / 60;
    b %= 60;
    cout << a % 24 << " " << b;
}
