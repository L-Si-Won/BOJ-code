#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[11][11];
bool visit[11];
int MIN=2e9;
int temp;

void dfs(int a, int cnt, int cost){
    if(cnt==n){
        if(arr[a][temp]>0) MIN=min(cost+arr[a][temp], MIN);
        return ;
    }

    for(int i=0; i<n; i++){
        if(arr[a][i]!=0 && visit[i]==false){
            visit[i]=true;
            dfs(i, cnt+1, cost+arr[a][i]);
            visit[i]=false;
        }
    }
}

void brute_force(){
    for(int i=0; i<n; i++){
        temp=i;
        visit[i]=true;
        dfs(i, 1, 0);
        visit[i]=false;
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
    brute_force();
    cout << MIN;
}
