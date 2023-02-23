#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 2e9

using namespace std;

int v, e, answer = INF;
vector<pair<int, int>> road[401];
bool visit[401];
int dist[401];

void bfs(int start){
    queue<pair<int, int>> q; //{위치, 누적거리}
    q.push({start, 0});
    dist[start] = INF;
    visit[start] = true;

    while (!q.empty()){
        int cur = q.front().first;
        int sum_dist = q.front().second;
        q.pop();

        for(int i = 0; i < road[cur].size(); i++){
            int next = road[cur][i].first;
            int next_dist = road[cur][i].second;

            if (visit[next] == false || sum_dist + next_dist <= dist[next]){
                visit[next] = true;
                dist[next] = sum_dist + next_dist;
                q.push({next, sum_dist + next_dist});
            }
        }
    }

    if (dist[start] != INF)
        answer = min(answer, dist[start]);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        road[a].push_back({b, c});
    }

    //bfs
    for(int i = 1; i <= v; i++){
        memset(visit, false, sizeof(visit));
        memset(dist, 0, sizeof(dist));
        bfs(i);
    }

    //output
    if (answer == INF)
        cout << -1;
    else
        cout << answer;
}
