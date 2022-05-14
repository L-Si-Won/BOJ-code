#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int arr[102][102];
bool visit[102][102];
int dist[102][102];
queue<pair<int, int>> q;

void bfs(int cur_x, int cur_y){
    visit[cur_x][cur_y]=true;
    q.push(make_pair(cur_x, cur_y));
    dist[cur_x][cur_y]++;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int cnt=4;
        while(cnt--){
            switch(cnt){
                case 3:
                    if(arr[x][y+1]==1 && visit[x][y+1]==false){
                        visit[x][y+1]=true;
                        q.push(make_pair(x, y+1));
                        dist[x][y+1]=dist[x][y]+1;
                    }
                    break;
                case 2:
                    if(arr[x+1][y]==1 && visit[x+1][y]==false){
                        visit[x+1][y]=true;
                        q.push(make_pair(x+1, y));
                        dist[x+1][y]=dist[x][y]+1;
                    }
                    break;
                case 1:
                    if(arr[x-1][y]==1 && visit[x-1][y]==false){
                        visit[x-1][y]=true;
                        q.push(make_pair(x-1, y));
                        dist[x-1][y]=dist[x][y]+1;
                    }
                    break;
                case 0:
                    if(arr[x][y-1]==1 && visit[x][y-1]==false){
                        visit[x][y-1]=true;
                        q.push(make_pair(x, y-1));
                        dist[x][y-1]=dist[x][y]+1;
                    }
                    break;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<n+1; i<i++){
        string s;
        cin >> s;
        for(int j=1; j<m+1; j++)
            arr[i][j]=s[j-1]-'0';
    }
    bfs(1,1);
    cout << dist[n][m];
}