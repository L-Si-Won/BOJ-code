#include <iostream>

using namespace std;

long long n;
int a[1500050];

void solve(){
    a[0]=0;
    a[1]=1;
    for(int i=2; i<1500000; i++)
        a[i]=(a[i-1]+a[i-2])%1000000;
    cout << a[n%1500000];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    solve();
}
