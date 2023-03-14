#include <iostream>
#include <vector>
#define INF 2e9

using namespace std;

struct edge{
    int s;
    int e;
    int t;
};

int tc, n, m, w;
int cost[501];

bool bellman_ford(vector<edge> v){
    cost[1] = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < v.size(); j++){
            int cur = v[j].s;
            int next = v[j].e;
            int ncost = v[j].t;

            if (cost[cur] + ncost < cost[next])
                cost[next] = cost[cur] + ncost;
        }
    }

    for(int i = 0; i < v.size(); i++){
        int cur = v[i].s;
        int next = v[i].e;
        int ncost = v[i].t;

        if (cost[cur] + ncost < cost[next])
            return true;
    }

    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> tc;
    while (tc--){
        cin >> n >> m >> w;

        int s, e, t;
        vector<edge> v;

        for(int i = 0; i < m; i++){
            cin >> s >> e >> t;

            v.push_back({s, e, t});
            v.push_back({e, s, t});
        }
        for(int i = 0; i < w; i++){
            cin >> s >> e >> t;

            v.push_back({s, e, -t});
        }
        for(int i = 0; i < 501; i++)
            cost[i] = INF;

        //bellman ford algorithm and output
        if (bellman_ford(v) == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
