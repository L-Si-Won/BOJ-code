#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];
int MIN=2e9;
bool visit[20];
int temp[10];

void solve(){
    int sum1=0;
    int sum2=0;

    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(i!=j){
                sum1 += arr[temp[i]][temp[j]];
            }
        }
    }

    int temp2[10];
    int k=0;
    for(int i=0; i<n; i++){
        if(visit[i]==false){
            temp2[k]=i;
            k++;
        }
    }
    
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(i!=j){
                sum2 += arr[temp2[i]][temp2[j]];
            }
        }
    }

    MIN=min(MIN, abs(sum1-sum2));
}

void dfs(int cnt, int num){
    if(cnt==n/2){
        solve();
        return ;
    }

    for(int i=num; i<n; i++){
        if(visit[i]==false){
            visit[i]=true;
            temp[cnt]=i;
            dfs(cnt+1, i+1);
            visit[i]=false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    visit[0]=true;
    dfs(1, 1); //temp[0]에 이미 0이 들어가있다고 생각->0은 무조건 포함
    cout << MIN;
}