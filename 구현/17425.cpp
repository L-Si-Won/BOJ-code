#include <iostream>

using namespace std;

int n, t;
long long sum[1000001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //calculate g(1) ~ g(1000000)
    for(int i = 1; i <= 1000000; i++){
        sum[i] += sum[i - 1];
        for(int j = 1; i * j <= 1000000; j++)
            sum[i * j] += i;
    }

    //input and output
    cin >> t;
    while (t--){
        cin >> n;
        cout << sum[n] << "\n";
    }
}
