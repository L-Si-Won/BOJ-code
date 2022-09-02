#include <iostream>

using namespace std;

int n, m, p;

void solve(){
    int a=1, b=1;
    int cnt=0;
    while(1){
        int temp=(a+b)%m;
        a=b;
        b=temp;
        cnt++;
        if(a%m==1 && b%m==1) break;
    }
    cout << n << " " << cnt << "\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> p;
    for(int i=1; i<p+1; i++){
        cin >> n >> m;
        solve();
    }
}
