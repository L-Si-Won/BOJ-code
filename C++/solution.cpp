#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20][20];
int MIN=2e9;
bool visit[20];
int temp[20];

void solve(int team){
    int sum1=0;
    int sum2=0;

    for(int i=0; i<team; i++){
        for(int j=0; j<team; j++){
            if(i!=j){
                sum1 += arr[temp[i]][temp[j]];
            }
        }
    }

    int temp2[20];
    int k=0;
    for(int i=0; i<n; i++){
        if(visit[i]==false){
            temp2[k]=i;
            k++;
        }
    }
    
    for(int i=0; i<n-team; i++){
        for(int j=0; j<n-team; j++){
            if(i!=j){
                sum2 += arr[temp2[i]][temp2[j]];
            }
        }
    }

    MIN=min(MIN, abs(sum1-sum2));
}

void dfs(int cnt, int num, int team){
    if(cnt==team){
        solve(team);
        return ;
    }

    for(int i=num; i<n; i++){
        if(visit[i]==false){
            visit[i]=true;
            temp[cnt]=i;
            dfs(cnt+1, i+1, team);
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
    for(int i=1; i<=n-1; i++)
        dfs(1, 1, i);
    cout << MIN;
}