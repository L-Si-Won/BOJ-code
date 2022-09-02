#include <iostream>

using namespace std;

int n, k, answer;
int order[101], mul[101];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=1; i<=k; i++)
        cin >> order[i];

    for(int i=1; i<=k; i++){
        //꽂혀있는 것을 사용
        bool flag=false;
        for(int j=1; j<=n; j++)
            if(mul[j]==order[i]) flag=true;
        if(flag==true) continue;

        //빈칸에 꽂기
        for(int j=1; j<=n; j++){
            if(mul[j]==0){
                mul[j]=order[i];
                flag=true;
                break;
            }
        }
        if(flag==true) continue;

        //뽑고 꽂기
        //꽂혀있는 것 중 가장 나중에 사용되는 것 뽑기
        int last=-1;
        int idx=-1;
        for(int j=1; j<=n; j++){
            int temp=0;
            for(int l=i+1; l<=k; l++){
                if(order[l]==mul[j]) break;
                temp++;
            }
            if(temp>last){
                last=temp;
                idx=j;
            }
        }
        mul[idx]=order[i];
        answer++;
    }
    cout << answer;
}
