#include <iostream>

using namespace std;

int r, c, MAX;
char arr[20][20];
bool visit[20][20];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

void dfs(int x, int y, int cnt, bool alpha[20]){
    for(int i=0; i<4; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && ny>=0 && nx<r && ny<c){
            if(visit[nx][ny]==false && alpha[arr[nx][ny]-'A']==false){
                visit[nx][ny]=true;
                alpha[arr[nx][ny]-'A']=true;
                dfs(nx, ny, cnt+1, alpha);
                visit[nx][ny]=false;
                alpha[arr[nx][ny]-'A']=false;
            }
        }
    }
    MAX=max(MAX, cnt);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> r >> c;
    for(int i=0; i<r; i++){
        string s;
        cin >> s;
        for(int j=0; j<c; j++)
            arr[i][j]=s[j];
    }
    bool alpha[26]={0};
    visit[0][0]=true;
    alpha[arr[0][0]-'A']=true;
    dfs(0, 0, 1, alpha);
    cout << MAX;
}