#include <iostream>

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

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    //통분해서 더하기
    a1*=b2;
    b1*=a2;
    a2*=b2;
    a1+=b1; //더한 분자 값은 a1
    
    //기약분수 구하기
    while(1){
        int temp=gcd(a1, a2);
        if(temp==1) break;

        a1/=temp;
        a2/=temp;
    }

    //출력
    cout << a1 << " " << a2;
}
