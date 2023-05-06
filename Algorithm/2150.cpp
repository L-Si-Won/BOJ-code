#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int v, e;
vector<int> g[10'001], rev_g[10'001];
vector<int> dfs_order, ssc_set[10'000];
bool visit[10'001];

void dfs(int cur){
    visit[cur] = true;

    for (int i = 0; i < g[cur].size(); i++){
        int next = g[cur][i];

        if (visit[next] == false)
            dfs(next);
    }

    dfs_order.push_back(cur);
}

void ssc_dfs(int cur, int ssc_cnt){
    visit[cur] = true;
    ssc_set[ssc_cnt].push_back(cur);

    for (int i = 0; i < rev_g[cur].size(); i++){
        int next = rev_g[cur][i];

        if (visit[next] == false)
            ssc_dfs(next, ssc_cnt);
    }
}

bool cmp(vector<int> a, vector<int> b){
    return a[0] < b[0] ? true : false;
}

int ssc(){
    //dfs 방문 순서 구하기
    for (int i = 1; i <= v; i++)
        if (visit[i] == false)
            dfs(i);

    //dfs 방문 순서의 역순으로 dfs 돌리기
    reverse(dfs_order.begin(), dfs_order.end());
    memset(visit, 0, sizeof(visit));
    int ssc_cnt = 0;
    for (int i = 0; i < dfs_order.size(); i++)
        if (visit[dfs_order[i]] == false)
            ssc_dfs(dfs_order[i], ssc_cnt++);

    //ssc 정렬
    for (int i = 0; i < ssc_cnt; i++)
        sort(ssc_set[i].begin(), ssc_set[i].end());
    sort(ssc_set, ssc_set + ssc_cnt, cmp);

    return ssc_cnt;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> v >> e;
    for (int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rev_g[b].push_back(a);
    }

    //find ssc and output
    int ssc_cnt = ssc();
    cout << ssc_cnt << "\n";
    for (int i = 0; i < ssc_cnt; i++){
        for (int j = 0; j < ssc_set[i].size(); j++)
            cout << ssc_set[i][j] << " ";
        cout << "-1\n";
    }
}
