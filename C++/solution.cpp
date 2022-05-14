#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[27][27];
bool visit[27][27];
int cont[1000];
int count_idx;

void dfs(int x, int y){
    visit[x][y]=true;
    cont[count_idx]++;
    int cnt=4;
    while(cnt--){
        switch(cnt){
            case 3:
                if(arr[x-1][y]==1 && visit[x-1][y]==false)
                    dfs(x-1, y);
                break;
            case 2:
                if(arr[x][y-1]==1 && visit[x][y-1]==false)
                    dfs(x, y-1);
                break;
            case 1:
                if(arr[x][y+1]==1 && visit[x][y+1]==false)
                    dfs(x, y+1);
                break;
            case 0:
                if(arr[x+1][y]==1 && visit[x+1][y]==false)
                    dfs(x+1, y);
                break;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<n+1; i++){
        string s;
        cin >> s;
        for(int j=1; j<n+1; j++)
            arr[i][j]=s[j-1]-'0';
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(visit[i][j]==false && arr[i][j]==1){
                dfs(i, j);
                count_idx++;
            }
        }
    }
    sort(cont, cont+count_idx);
    cout << count_idx << "\n";
    for(int i=0; i<count_idx; i++)
        cout << cont[i] << "\n";
}