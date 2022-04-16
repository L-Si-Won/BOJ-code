#include <iostream>

using namespace std;

int cnt;
int a[10]={0,9,90,900,9000,90000,900000,9000000,90000000,900000000};

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int idx=1;
    int temp=n;
    if(n/10==0){
        cout << n;
        return 0;
    }
    while(1){
        if(temp/10!=0){
            cnt += a[idx]*idx;
            temp /= 10;
            idx++;
        }
        else{
            int sum=0;
            for(int j=1; j<idx; j++)
                sum+=a[j];
            cnt += (n-sum)*idx;
            break;
        }
    }
    cout << cnt;
}