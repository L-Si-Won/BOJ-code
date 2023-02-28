#include <iostream>
#include <algorithm>

using namespace std;

int n_cnt, arr[50], n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n_cnt;
    for(int i = 0; i < n_cnt; i++)
        cin >> arr[i];

    //asc sort
    sort(arr, arr + n_cnt);

    //calculate n
    n = arr[0] * arr[n_cnt - 1];

    //output
    cout << n;
}
