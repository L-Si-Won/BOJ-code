#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int w, h; //열, 행
int arr[20][20];
int dist[20][20];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

void bfs(int r, int c){
    bool visit[20][20]={0, }; //초기화 필수!!!
    queue<pair<int, int>> q;

    visit[r][c]=true;
    q.push({r, c});

    while(!q.empty()){
        int cr=q.front().first;
        int cc=q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nr=cr+dx[i];
            int nc=cc+dy[i];

            if(nr>=0 && nc>=0 && nr<h && nc<w){
                if(arr[nr][nc]!=-1 && visit[nr][nc]==false){
                    visit[nr][nc]=true;
                    q.push({nr, nc});
                    dist[nr][nc]=dist[cr][cc]+1;
                }
            }
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
        
        vector<pair<int, int>> v(1);
        memset(arr, 0, sizeof(arr));

        for(int i=0; i<h; i++){
            string s;
            cin >> s;
            for(int j=0; j<w; j++){
                arr[i][j]=s[j];
                if(arr[i][j]=='o') v[0]={i, j};
                if(arr[i][j]=='*') v.push_back({i, j});
                if(arr[i][j]=='x') arr[i][j]=-1;
            }
        }

        int result[20][20]={0, };
        for(int i=0; i<v.size(); i++){
            memset(dist, 0, sizeof(dist));
            bfs(v[i].first, v[i].second);

            for(int j=0; j<v.size(); j++)
                result[i][j]=dist[v[j].first][v[j].second];
        }

        vector<int> clean;
        for(int i=1; i<v.size(); i++)
            clean.push_back(i);
        
        int ans=2e9;
        bool flag=true;

        do{
            int cur=result[0][clean[0]];
            if(cur==0){
                flag=false;
                break;
            }

            for(int i=0; i<v.size()-2; i++)
                cur += result[clean[i]][clean[i+1]];
            ans=min(ans, cur);
        }while(next_permutation(clean.begin(), clean.end()));

        if(flag==false) cout << -1 << "\n";
        else cout << ans << "\n";
    }
}