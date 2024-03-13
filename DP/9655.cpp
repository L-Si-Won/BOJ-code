#include <iostream>

using namespace std;

int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    if (n % 2 != 0)
        cout << "SK";
    else
        cout << "CY";
}
