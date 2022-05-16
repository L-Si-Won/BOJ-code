#include <iostream>

using namespace std;

int n ,m;
char arr[50][50];
bool visit[50][50];
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};
int dist[50][50];

bool dfs(int cur_x, int cur_y, char ch, int cnt){
    if(visit[cur_x][cur_y]==true){
        if(cnt-dist[cur_x][cur_y]>=4)
            return true;
        else
            return false;
    }
    visit[cur_x][cur_y]=true;
    dist[cur_x][cur_y]=cnt;
    for(int i=0; i<4; i++){
        int nx=cur_x+dx[i];
        int ny=cur_y+dy[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m && arr[nx][ny]==ch){
            if(dfs(nx, ny, ch, cnt+1))
                return true;
        }
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++)
            arr[i][j]=s[j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visit[i][j]==false){
                if(dfs(i, j, arr[i][j], 0)){
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
}