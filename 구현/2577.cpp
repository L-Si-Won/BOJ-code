#include <iostream>

using namespace std;

int n, result = 1, num[10];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 3; i++){
        cin >> n;
        result *= n;
    }

    while (result != 0){
        num[result % 10]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i++)
        cout << num[i] << "\n";
}
