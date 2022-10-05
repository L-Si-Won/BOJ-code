#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, x, answer;
int go[1001], back[1001], dist[1001];
vector<pair<int, int>> v[1001]; //(도착점, 비용)

//갈 때 시간
void dijkstra_go(int start){
    queue<pair<int, int>> q;
    q.push({start, 0});
    int min_dist=2e9;
    
    while(!q.empty()){
        int cur=q.front().first;
        int ccost=q.front().second;
        q.pop();

        if(cur==x) min_dist=min(min_dist, ccost);

        for(int i=0; i<v[cur].size(); i++){
            int next=v[cur][i].first;
            int ncost=v[cur][i].second;

            if(ccost+ncost<dist[next]){
                q.push({next, ccost+ncost});
                dist[next]=ccost+ncost;
            }
        }
    }

    go[start]=min_dist;
}

//올 때 시간
void dijkstra_back(int end){
    queue<pair<int, int>> q;
    q.push({x, 0});
    int min_dist=2e9;

    while(!q.empty()){
        int cur=q.front().first;
        int ccost=q.front().second;
        q.pop();

        if(cur==end) min_dist=min(min_dist, ccost);

        for(int i=0; i<v[cur].size(); i++){
            int next=v[cur][i].first;
            int ncost=v[cur][i].second;

            if(ccost+ncost<dist[next]){
                q.push({next, ccost+ncost});
                dist[next]=ccost+ncost;
            }
        }
    }

    back[end]=min_dist;
}

void Init_dist(){
    for(int i=0; i<=1001; i++)
        dist[i]=2e9;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> x;
    for(int i=1; i<=m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    //다익스트라
    Init_dist();
    for(int i=1; i<=n; i++){
        dijkstra_go(i);
        Init_dist();
        dijkstra_back(i);
        Init_dist();
    }

    //최대 소요시간
    for(int i=1; i<=n; i++)
        answer=max(answer, go[i]+back[i]);

    cout << answer;
}
