#include <iostream>

using namespace std;

int n, Max, order;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 9; i++){

        cin >> n;

        if (n > Max){
            Max = n;
            order = i + 1;
        }
    }

    cout << Max << "\n";
    cout << order << "\n";
}
