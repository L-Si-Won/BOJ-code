#include <iostream>
#include <algorithm>

using namespace std;

int w, h;
int arr[52][52];
bool visit[52][52];
int land;

void dfs(int x, int y){
    visit[x][y]=true;
    int cnt=8;
    while(cnt--){
        switch(cnt){
            case 7:
                if(arr[x-1][y-1]==1 && visit[x-1][y-1]==false)
                    dfs(x-1, y-1);
                break;
            case 6:
                if(arr[x-1][y+1]==1 && visit[x-1][y+1]==false)
                    dfs(x-1, y+1);
                break;
            case 5:
                if(arr[x+1][y-1]==1 && visit[x+1][y-1]==false)
                    dfs(x+1, y-1);
                break;
            case 4:
                if(arr[x+1][y+1]==1 && visit[x+1][y+1]==false)
                    dfs(x+1, y+1);
                break;
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

    while(1){
        cin >> w >> h;
        if(w==0 && h==0) break;

        for(int i=1; i<h+1; i++)
            for(int j=1; j<w+1; j++)
                cin >> arr[i][j];

        for(int i=1; i<h+1; i++){
            for(int j=1; j<w+1; j++){
                if(arr[i][j]==1 && visit[i][j]==false){
                    dfs(i, j);
                    land++;
                }
            }
        }
        cout << land << "\n";

        land=0;
        fill(&arr[0][0], &arr[51][52], 0);
        fill(&visit[0][0], &visit[51][52], 0);
    }
}
