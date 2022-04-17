#include <iostream>
#include <algorithm>

using namespace std;
int gcd(int a, int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int func(int n, int m, int x, int y){
    if(n < m)
        return func(m, n , y, x);
    int a=x, b=x;
    int cnt=x;
    int MAX=lcm(n, m);
    if(b>m){
        b=b%m;
        if(b==0)
            b=m;
    }
    while(cnt<=MAX){
        if(a==x && b==y)
            return cnt;
        b+=n-m;
        if(b>m){
            b=b%m;
            if(b==0)
                b=m;
        }
        cnt += n;
    }
    return -1;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m, x, y;
    int test_case;
    cin >> test_case;
    for(int i=0; i<test_case; i++){
        cin >> n >> m >> x >> y;
        cout << func(n, m, x, y) << "\n";
    }
}