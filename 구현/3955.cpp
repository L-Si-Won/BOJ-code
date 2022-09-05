#include <iostream>

using namespace std;

int t, k, c;

//확장 유클리드 호제법
//ax+by=gcd(a, b)를 만족하는 x, y를 반환
pair<int, int> EEA(int a, int b){
    if(b!=0){
        pair<int, int> temp=EEA(b, a%b);
        return {temp.second, temp.first-(a/b)*temp.second};
    }
    else return {1, 0};
}

//ax=1(mod b)를 만족하는 x를 반환
long long mod(int a, int b){
    return (EEA(a, b).first+b)%b;
}

//최대공약수 구하기
int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b, a%b);
}

void solve(){
    //k와 c의 최대공약수가 1일때만 답이 존재
    if(GCD(k, c)!=1){
        cout << "IMPOSSIBLE\n";
        return;
    }

    long long ans=mod(c, k); //인자 전달 순서 유의
    while(c*ans<=k) ans+=k;

    if(ans>1e9) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> k >> c;
        solve();
    }
}
