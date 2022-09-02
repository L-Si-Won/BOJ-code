#include <iostream>
#include <algorithm>

using namespace std;

int n, a[10003];
int pay;

void solve(){
    for(int i=1; i<=n; i++){
        if(a[i+1] > a[i+2]){
            int cnt=min(a[i], a[i+1]-a[i+2]);
            pay += 5*cnt;
            a[i]-=cnt;
            a[i+1]-=cnt;
            
            int cnt2=min(a[i], min(a[i+1], a[i+2]));
            pay += 7*cnt2;
            a[i]-=cnt2;
            a[i+1]-=cnt2;
            a[i+2]-=cnt2;
        }
        else{
            int cnt=min(a[i], min(a[i+1], a[i+2]));
            pay += 7*cnt;
            a[i]-=cnt;
            a[i+1]-=cnt;
            a[i+2]-=cnt;

            int cnt2=min(a[i], a[i+1]);
            pay += 5*cnt2;
            a[i]-=cnt2;
            a[i+1]-=cnt2;
        }
        pay+=3*a[i];
        a[i]=0;
    }
    cout << pay;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    solve();
}
