#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
vector<pair<int, int>> jewel;
vector<int> c;
priority_queue<int> candidate;
long long answer;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first < b.first)
        return true;
    else if (a.first > b.first)
        return false;
    else if (a.first == b.first){
        if (a.second < b.second)
            return true;
        else
            return false;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int m, v;
        cin >> m >> v;
        jewel.push_back({m, v});
    }
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        c.push_back(a);
    }

    //sort
    sort(c.begin(), c.end());
    sort(jewel.begin(), jewel.end(), cmp);

    //solve
    int idx = 0; //후보 보석 개수
    for(int i = 0; i < k; i++){
        while (idx < n && c[i] >= jewel[idx].first)
            candidate.push(jewel[idx++].second);
        
        if (!candidate.empty()){
            answer += candidate.top();
            candidate.pop();
        }
    }

    //output
    cout << answer;
}
