#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, d, answer;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }
};

void sol(){
    priority_queue<int, vector<int>, cmp> q;
    
    for(int i = 0; i < n; i++){
        int left = v[i].second - d;
        int right = v[i].second;

        if (v[i].first >= left)
            q.push(v[i].first);
        
        while(!q.empty() && q.top() < left)
            q.pop();
        
        answer = max(answer, (int)q.size());
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++){
        int h, o;
        cin >> h >> o;
        if (h > o)
            swap(h, o);
        v.push_back({h, o});
    }
    cin >> d;

    //sort
    sort(v.begin(), v.end(), compare);

    //solve
    sol();

    //output
    cout << answer;
}
