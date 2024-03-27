#include <iostream>

using namespace std;

int n, x, arr[250000];
int sum[250000], Max, cnt;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //add
    sum[0] = arr[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + arr[i];

    //search
    Max = sum[x - 1];
    cnt = 1;
    for (int i = x; i < n; i++){
        int temp = sum[i] - sum[i - x];

        if (temp > Max){
            Max = temp;
            cnt = 1;
        }
        else if (temp == Max)
            cnt++;
    }

    //output
    if (Max == 0)
        cout << "SAD\n";
    else
        cout << Max << "\n" << cnt << "\n";
}
