#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
bool prime_check[10000001];
vector<int> prime;
vector<int> answer;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    if(n==1) return 0;

    //천만 이하 소수구하기
    memset(prime_check, true, sizeof(prime_check));
    for(int i=2; i<=sqrt(10000000); i++)
        for(int j=i*2; j<=10000000; j+=i)
            prime_check[j]=false;
    for(int i=2; i<=10000000; i++)
        if(prime_check[i]) prime.push_back(i);

    //소인수분해
    while(1){
        if(n==1) break;

        int temp;
        for(int i=0; i<prime.size(); i++){
            if(n%prime[i]==0){
                temp=prime[i];
                break;
            }
        }

        answer.push_back(temp);
        n/=temp;
    }

    //출력
    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << "\n";
}
