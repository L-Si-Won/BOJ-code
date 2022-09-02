#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
int s;
int arr[20];
int temp[20];
bool visit[20];
int a;

void dfs(int cnt, int num, int b){
    if(cnt==b){
        int sum=0;
        for(int i=0; i<n; i++)
            sum += temp[i];
        if(sum==s) a++;
        return ;
    }

    for(int i=num; i<n; i++){
        if(visit[i]==false){
            visit[i]=true;
            temp[cnt]=arr[i];
            dfs(cnt+1, i+1, b);
            visit[i]=false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=1; i<n+1; i++)
        dfs(0 ,0, i);
    cout << a;
}
