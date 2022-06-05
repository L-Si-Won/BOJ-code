#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int n, m; //행 열, 좌표(n,m)
int arr[50][50];
bool visit[50][50];
int clear_cnt;
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};
int r, c, d;

void dfs(){
    for(int i=0; i<4; i++){
        int nd=(d+3-i)%4;
        int nr=r+dx[nd];
        int nc=c+dy[nd];

        if(arr[nr][nc]==1) continue;
        if(arr[nr][nc]==0 && visit[nr][nc]==false){
            visit[nr][nc]=true;
            r=nr;
            c=nc;
            d=nd;
            clear_cnt++;
            dfs();
        }
    }

    int bd=d>1?d-2:d+2;
    int br=r+dx[bd];
    int bc=c+dy[bd];

    if(arr[br][bc]==0){
        r=br;
        c=bc;
        dfs();
    }
    else{
        cout << clear_cnt;
        exit(0);
    }
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    cin >> r >> c >>d;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    visit[r][c]=true;
    clear_cnt++;
    dfs();
}