#include <iostream>

using namespace std;

long long n, k;
long long d=1000000007;
long long f[4000001];
long long inv[4000001];

long long power(long long x, long long y){
    long long ret=1;
    while(y>0){
        if(y%2!=0){
            ret*=x;
            ret%=d;
        }
        x*=x;
        x%=d;
        y/=2;
    }
    return ret;
}

void fac(){
    f[1]=1;
    for(int i=2; i<=4000000; i++)
        f[i]=(f[i-1]*i)%d;
    inv[n]=power(f[n], d-2);
    for(int i=n-1; i>0; i--)
        inv[i]=(inv[i+1]*(i+1))%d;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    fac();
    if(n==k || k==0){
        cout << 1;
        return 0;
    }
    long long result=(f[n]*inv[n-k])%d;
    result=(result*inv[k])%d;
    cout << result;
}