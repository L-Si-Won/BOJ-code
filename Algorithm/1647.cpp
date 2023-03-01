#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, answer = 2e9;
vector<pair<int, int>> v[100001];
bool visit[100001];

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int prim(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({1, 0});
    int sum_cost = 0;
    int max_cost = 0;

    while (!q.empty()){
        int cur = q.top().first;
        int cost = q.top().second;
        q.pop();

        if (visit[cur] == true)
            continue;

        visit[cur] = true;
        sum_cost += cost;
        max_cost = max(max_cost, cost);

        for(int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i].first;
            int ncost = v[cur][i].second;

            if (visit[next] == false)
                q.push({next, ncost});
        }
    }

    return sum_cost - max_cost;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    //devide area and prim algorithm
    answer = prim();

    //output
    cout << answer;
}
