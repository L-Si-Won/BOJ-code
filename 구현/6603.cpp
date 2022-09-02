#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int arr[13];
int temp[6];
bool visit[13];

void dfs(int cnt, int num){
    if(cnt==6){
        for(int i=0; i<6; i++)
            cout << temp[i] << " ";
        cout << "\n";
        return ;
    }

    for(int i=num; i<n; i++){
        if(visit[i]==false){
            visit[i]=true;
            temp[cnt]=arr[i];
            dfs(cnt+1, i+1);
            visit[i]=false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(1){
        cin >> n;
        if(n==0) break;

        memset(arr, 0, sizeof(int)*13);
        memset(temp, 0, sizeof(int)*6);
        memset(visit, false, sizeof(bool)*13);
        for(int i=0; i<n; i++)
            cin >> arr[i];

        dfs(0, 0);
        cout << "\n";
    }
}
