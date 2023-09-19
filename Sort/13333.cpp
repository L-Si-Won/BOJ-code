#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1000];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //sort
    sort(arr, arr + n);

    //calculate q-index
    for (int i = 0; i <= n; i++){
        
        auto a = lower_bound(arr, arr + n, i) - arr;
        auto b = upper_bound(arr, arr + n, i) - arr;

        for (int j = a; j <= b; j++){
            if (j == n - i){
                cout << i;
                return 0;
            }
        }
    }
}
