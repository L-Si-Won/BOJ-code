#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n % 4 == 0){
        if (n % 100 != 0 || n % 400 == 0)
            cout << 1;
        else
            cout << 0;
    }
    else
        cout << 0;
}
