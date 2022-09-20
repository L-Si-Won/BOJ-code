#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int n, cnt;
bool prime_check[4000001];
vector<int> prime;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    if(n==1){
        cout << 0;
        return 0;
    }
    
    //소수구하기
    memset(prime_check, true, sizeof(prime_check));
    for(int i=2; i<=sqrt(4000000); i++)
        for(int j=i*2; j<=4000000; j+=i)
            prime_check[j]=false;
    for(int i=2; i<=4000000; i++)
        if(prime_check[i]) prime.push_back(i);

    //연속합 구하기
    int temp=2;
    int start=0, end=0;
    while(start<=end && end<prime.size()){
        if(temp<n){
            end++;
            temp+=prime[end];
        }
        else if(temp==n){
            cnt++;
            end++;
            temp+=prime[end];
        }
        else if(temp>n){
            temp-=prime[start];
            start++;
        }
    }
    cout << cnt;
}
