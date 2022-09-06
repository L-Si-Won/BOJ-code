#include <iostream>

using namespace std;

int n, k, cnt;
int num[1001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=0; i<=n; i++)
        num[i]=i;
    
    while(1){
        int p;
        //소수 찾기
        for(int i=2; i<=n; i++){
            if(num[i]!=0){
                p=i;
                break;
            }
        }

        //p의 배수 지우기
        for(int i=p; i<=n; i++){
            //num[i]!=0 -> 중복으로 지우는 것 방지
            if(i%p==0 && num[i]!=0){
                num[i]=0;
                cnt++;
                //k번째 지우는 수 찾기
                if(cnt==k){
                    cout << i;
                    return 0;
                }
            }
        }
    }
}
