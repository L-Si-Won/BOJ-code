#include <iostream>

using namespace std;

int n, m;
int arr[100001];
int sum[100001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    //누적 합 구하기
    sum[1]=arr[1];
    for(int i=2; i<=n; i++)
        sum[i]=sum[i-1]+arr[i];

    while(m--){
        int a, b;
        cin >> a >> b;

        cout << sum[b]-sum[a-1] << "\n";
    }
}
