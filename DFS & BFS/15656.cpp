#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int temp[9];
bool visit[9];

void dfs(int cnt){
    if(cnt==m){
        for(int i=0; i<m; i++)
            cout << temp[i] << " ";
        cout << "\n";
        return ;
    }

    for(int i=1; i<n+1; i++){
        temp[cnt]=arr[i];
        dfs(cnt+1);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<n+1; i++)
        cin >> arr[i];
    sort(arr+1, arr+n+1);
    dfs(0);
}
