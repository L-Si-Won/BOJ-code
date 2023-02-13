/*
#include <iostream>
#include <cmath>

using namespace std;

int n;

bool prime_check(int num){
    bool flag=true;
    for(int i=2; i<=sqrt(num); i++){
        if(num%i==0){
            flag=false;
            break;
        }
    }
    return flag;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(1){
        cin >> n;
        if(n==0) break;

        bool flag=false;
        int a;
        for(int i=3; i<=n/2; i+=2){
            if(prime_check(i) && prime_check(n-i)){
                flag=true;
                a=i;
                break;
            }
        }

        if(flag)
            printf("%d = %d + %d\n", n, a, n-a);
        else
            cout << "Goldbach's conjecture is wrong.\n";
    }
}
***********************************************************************************************************/

#include <iostream>

using namespace std;

int n;
bool prime[1000001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=2; i*i<=1000000; i++){
        if (prime[i] == 0)
            for(int j=i+i; j<=1000000; j+=i)
                prime[j] = 1;
    }

    //추측 검증
    while(1){
        cin >> n;
        if(n==0) break;

        bool flag=false;
        int a;
        for(int i=3; i<=n; i+=2){
            if(prime[i] == 0 && prime[n-i] == 0){
                a = i;
                flag = true;
                break;
            }
        }

        if(flag)
            printf("%d = %d + %d\n", n, a, n-a);
        else
            cout << "Goldbach's conjecture is wrong.\n";
    }
}
