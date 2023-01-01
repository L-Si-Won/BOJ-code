#include <iostream>
#include <queue>

using namespace std;

int n, m, answer=2e9;
int map[1000][1000];
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0 ,-1};
bool visit[1000][1000][2];

void shortestPath(){
    queue<pair<pair<int, int>, pair<int, bool>>> q; //{{좌표}, {거리, 벽 부수기}}
    q.push({{0, 0}, {1, false}});
    visit[0][0][0]=true;

    while(!q.empty()){
        int cx=q.front().first.first;
        int cy=q.front().first.second;
        int cdist=q.front().second.first;
        bool wall=q.front().second.second;
        q.pop();

        if(cx==n-1 && cy==m-1) answer=min(answer, cdist);

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<m){ //다음 위치가 map 범위
                if(wall==true){ //이미 벽을 한 번 부숨
                    if(map[nx][ny]==0 && visit[nx][ny][wall]==false){ //이동가능한 곳 && 방문x
                        visit[nx][ny][wall]=true;
                        q.push({{nx, ny}, {cdist+1, wall}});
                    }
                }
                else if(wall==false){ //아직 벽을 부수지 않음
                    if(map[nx][ny]==0){ //이동가능한 곳
                        if(visit[nx][ny][wall]==false){ //방문x
                            visit[nx][ny][wall]=true;
                            q.push({{nx, ny}, {cdist+1, wall}});
                        }
                    }
                    else if(map[nx][ny]==1){ //이동불가한 곳
                        if(visit[nx][ny][wall]==false){ //방문x
                            visit[nx][ny][wall]=true;
                            q.push({{nx, ny}, {cdist+1, true}}); //벽을 부순 것으로 처리
                        }
                    }
                }
            }
        }
    }
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
            map[i][j]=s[j]-'0';
    }

    shortestPath();

    if(answer==2e9) cout << -1;
    else cout << answer;
}
