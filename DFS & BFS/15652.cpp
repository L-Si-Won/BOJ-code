#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool visit[9];

void dfs(int num, int cnt){
    if(cnt==m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return ;
    }
    for(int i=num; i<n+1; i++){
            arr[cnt]=i;
            dfs(i, cnt+1);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    dfs(1, 0);
}
