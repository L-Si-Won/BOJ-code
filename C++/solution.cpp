#include <iostream>
#include <queue>

using namespace std;

int n ,m;
int arr[1000][1000];
bool visit[1000][1000];
int dist[1000][1000];
queue<pair<int,int>> q;
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m &&visit[nx][ny]==false && arr[nx][ny]==0){
                q.push({nx, ny});
                visit[nx][ny]=true;
                arr[nx][ny]=1;
                dist[nx][ny]=dist[x][y]+1;
            }
        }
    }
}

int check_tomato(){
    int MAX=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j]==0)
                return -1;
            MAX=max(MAX, dist[i][j]);
        }
    }
    return MAX-1;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

    int check=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(arr[i][j]==1) check++;
    if(check==n*m){
        cout << "0";
        exit(0);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==-1) dist[i][j]=-1;
            if(visit[i][j]==false && arr[i][j]==1){
                q.push({i, j});
                visit[i][j]=true;
                dist[i][j]=1;
            }
        }
    }
    bfs();
    cout << check_tomato();
}