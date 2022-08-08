#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, answer;
char arr[100][100];
bool visit[100][100];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

void bfs(int x, int y, char color){
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y]=true;

    while(!q.empty()){
        int cx=q.front().first;
        int cy=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n){
                if(arr[nx][ny]==color && visit[nx][ny]==false){
                    q.push({nx, ny});
                    visit[nx][ny]=true;
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
            arr[i][j]=s[j];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j]==false){
                bfs(i, j, arr[i][j]);
                answer++;
            }
        }
    }
    cout << answer << " ";

    answer=0;
    memset(visit, false, sizeof(visit));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(arr[i][j]=='R') arr[i][j]='G';

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j]==false){
                bfs(i, j, arr[i][j]);
                answer++;
            }
        }
    }
    cout << answer;
}