#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e, answer;
vector<pair<int, int>> g[10001];
bool visit[10001];

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({1, 0});
    int min_dist = 0;

    for(int i = 0; i < v; i++){
        int next, next_dist;

        while (!q.empty()){
            next = q.top().first;
            next_dist = q.top().second;
            q.pop();

            if (visit[next] == false)
                break;
        }

        visit[next] = true;
        min_dist += next_dist;
        for(int j = 0; j < g[next].size(); j++)
            q.push({g[next][j]});
    }

    return min_dist;
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
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    //prim algorithm
    answer = prim();

    //output
    cout << answer;
}
