#include <iostream>

using namespace std;

int n, x, a;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> x;

    while (n--){
        cin >> a;
        if (a < x)
            cout << a << " ";
    }
}
