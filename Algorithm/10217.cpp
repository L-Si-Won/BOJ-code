#include <iostream>
#include <vector>
#include <queue>
#define INF 2e9

using namespace std;

int t, n, m, k, answer;
vector<pair<int, pair<int, int>>> ticket[10001];
int time[101][10001];

void dijkstra(){
    //{현재위치, {누적비용, 누적시간}}
    queue<pair<int, pair<int, int>>> q;
    q.push({1, {0, 0}});
    time[1][0] = 0;

    while (!q.empty()){
        int cur = q.front().first;
        int ccost = q.front().second.first;
        int ctime = q.front().second.second;
        q.pop();

        if (time[cur][ccost] < ctime)
            continue;

        for(int i = 0; i < ticket[cur].size(); i++){
            int next = ticket[cur][i].first;
            int ncost = ticket[cur][i].second.first;
            int ntime = ticket[cur][i].second.second;

            if (ccost + ncost <= m && ctime + ntime < time[next][ccost + ncost]){
                for(int j = ccost + ncost + 1; j <= m; j++){
                    if (time[next][j] <= ctime + ntime)
                        break;
                    time[next][j] = ctime + ntime;
                }
                time[next][ccost + ncost] = ctime + ntime;
                q.push({next, {ccost + ncost, ctime + ntime}});
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (t--){
        //init
        for(int i = 0; i < 101; i++)
            for(int j = 0; j < 10001; j++)
                time[i][j] = INF;
        for(int i = 0; i < 10001; i++)
            ticket[i].clear();
        answer = INF;

        //input
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++){
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            ticket[u].push_back({v, {c, d}});
        }
        
        //dijkstra
        dijkstra();

        //output
        for(int i = 0; i <= m; i++)
            answer = min(answer, time[n][i]);

        if (answer == INF)
            cout << "Poor KCM\n";
        else
            cout << answer << "\n";
    }
}
