#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

string p;
int k;
bool prime_check[1000001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> p >> k;

    //k미만인 소수 구하기
    memset(prime_check, true, sizeof(prime_check));
    for(int i=2; i<sqrt(k); i++)
        for(int j=i*2; j<=k; j+=i)
            prime_check[j]=false;

    //암호 판단
    bool flag=true;
    int answer;
    for(int i=2; i<k; i++){
        if(!prime_check[i]) continue; //소수가 아니면 생략
        
        int ret=0;
        for(int j=0; j<p.size(); j++)
            ret=(ret*10+p[j]-'0')%i;
        
        if(ret==0){ //p가 소수 i로 나누어 떨어지면
            answer=i;
            flag=false;
            break;
        }
    }

    //출력
    if(flag) cout << "GOOD";
    else cout << "BAD " << answer;
}
