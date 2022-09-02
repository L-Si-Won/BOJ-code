#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n;
vector<int> edge[3001];
bool visit[3001];
bool cycle[3001];
int dist[3001];
int pre[3001];
bool find_cycle;

void bfs(){
    queue<pair<int, int>> q;
    for(int i=1; i<n+1; i++){
        if(cycle[i]==true){
            q.push({i, 0});
            visit[i]=true;
        }
    }
    while(!q.empty()){
        int cur=q.front().first;
        int dis=q.front().second;
        q.pop();
        visit[cur]=true;

        for(int i=0; i<edge[cur].size(); i++){
            int next=edge[cur][i];
            if(visit[next]==false){
                dist[next]=dis+1;
                q.push({next, dist[next]});
            }
        }
    }
}

void check_cycle(int cur){
    visit[cur]=true;
    for(int i=0; i<edge[cur].size(); i++){
        if(find_cycle) return;
        int next=edge[cur][i];
        if(visit[next]==true){
            if(pre[cur]!=next){
                cycle[cur]=true;
                find_cycle=true;
                while(cur != next){
                    cycle[pre[cur]]=true;
                    cur=pre[cur];
                }
                return;
            }
        }
        else{
            pre[next]=cur;
            check_cycle(next);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<n+1; i++){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    check_cycle(1);
    memset(visit, false, sizeof(bool)*3001);
    bfs();
    for(int i=1; i<n+1; i++)
        cout << dist[i] << " ";
}
