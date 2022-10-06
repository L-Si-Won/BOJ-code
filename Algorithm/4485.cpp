#include <iostream>
#include <queue>

using namespace std;

int n, t=1;
int arr[125][125];
int dist[125][125]; //누적 비용
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void bfs(){
    queue<pair<pair<int, int>, int>> q; //((x,y), cost)
    q.push({{0, 0}, arr[0][0]});
    dist[0][0]=arr[0][0];
    
    while(!q.empty()){
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int ccost=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            int ncost=arr[nx][ny];

            if(nx>=0 && ny>=0 && nx<n && ny<n){
                if(ccost+ncost<dist[nx][ny]){
                    q.push({{nx, ny}, ccost+ncost});
                    dist[nx][ny]=ccost+ncost;
                }
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(1){
        cin >> n;
        if(n==0) break;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> arr[i][j];
                dist[i][j]=2e9;
            }
        }
        
        bfs();
        cout << "Problem " << t++ << ": " << dist[n-1][n-1] << "\n";
    }
}
