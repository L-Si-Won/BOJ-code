#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> v[100001]; //연결된 정점, 거리
bool visit[100001];
int temp_ans;
int far_point;

void dfs(int cur, int dist){
    visit[cur]=true;
    if(temp_ans < dist){
        temp_ans = dist;
        far_point=cur;
    }
    for(int i=0; i<v[cur].size(); i++){
        if(visit[v[cur][i].first]==false){
            dfs(v[cur][i].first, dist+v[cur][i].second);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    dfs(1, 0);
    temp_ans=0;
    memset(visit, false, sizeof(visit));
    dfs(far_point, 0);
    cout << temp_ans;
}