#include <iostream>
#include <algorithm>

using namespace std;

int n, b, a;
int price[100'001];
long long sum[100'001], half[100'001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> b >> a;
    for (int i = 1; i <= n; i++)
        cin >> price[i];

    sort(price, price + n + 1);
    
    sum[1] = price[1];
    half[1] = price[1] / 2;
    for (int i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + price[i];
        half[i] = half[i - 1] + price[i] / 2;
    }

    for (int i = n; i > 0; i--) {
        if (sum[i] - (half[i] - half[i - a > 0 ? i - a : 0]) <= b) {
            cout << i << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";

    return 0;
}
