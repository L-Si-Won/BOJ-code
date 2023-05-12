#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<pair<int, int>, int>> v;
int parent[100001];
int set_size[100001];
int set_rank[100001];

void init(){
    for(int i = 0; i < 100001; i++){
        parent[i] = i;
        set_size[i] = 1;
        set_rank[i] = 1;
    }
}

int find(int node){
    if (parent[node] == node)
        return node;

    parent[node] = find(parent[node]);

    return parent[node];
}

void Union(int x, int y){
    x = find(x);
    y = find(y);

    if (x == y)
        return ;

    if (set_rank[x] < set_rank[y]){
        parent[x] = y;
        set_size[y] += set_size[x];
    }
    else{
        parent[y] = x;
        set_size[x] += set_size[y];

        if (set_rank[x] == set_rank[y])
            set_rank[x]++;
    }
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.second > b.second ? true : false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({{x, y}, z});
    }

    init();

    sort(v.begin(), v.end(), cmp);

    long long answer = 0;
    for(int i = 0; i < v.size(); i++){
        int a = v[i].first.first;
        int b = v[i].first.second;
        int w = v[i].second;

        a = find(a);
        b = find(b);

        answer += ((long long)set_size[a] * set_size[b] * w);
        Union(a, b);
    }

    cout << answer;
}
