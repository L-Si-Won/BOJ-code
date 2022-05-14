#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
bool visit[400][400];
int dist[400][400];
int start[2];
int arrive[2];
int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={2,1,-1,-2,-2,-1,1,2};
queue<pair<int, int>> q;

void bfs(int cur_x, int cur_y){
    q.push(make_pair(cur_x, cur_y));
    visit[cur_x][cur_y]=true;

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(x==arrive[0] && y==arrive[1])
            break;
        
        for(int i=0; i<8; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<n && visit[nx][ny]==false){
                q.push({nx,ny});
                visit[nx][ny]=true;
                dist[nx][ny]=dist[x][y]+1;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> k;
    while(k--){
        cin >> n;
        cin >> start[0] >> start[1];
        cin >> arrive[0] >> arrive[1];
        bfs(start[0], start[1]);
        cout << dist[arrive[0]][arrive[1]] << "\n";

        while(!q.empty()) q.pop();
        fill(&visit[0][0], &visit[399][400], 0);
        fill(&dist[0][0], &dist[399][400], 0);
    }
}