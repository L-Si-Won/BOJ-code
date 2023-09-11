#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int T, n, m;
vector<pair<int, int>> cafe;
pair<int, int> num[100'001];

void solve(){

    stack<pair<int, int>> s;
    int idx = 0;
    int order = 1;

    while (!(cafe[idx].first == 0 && cafe[idx].second == 0))
        s.push(cafe[idx++]);

    pair<int, int> cur = cafe[idx]; //{0, 0}
    num[order++] = cur;
    while (!s.empty()){
        num[order++] = s.top();
        cur = s.top();
        s.pop();
    }

    for (int i = idx + 1; i < n; i++){

        pair<int, int> next = cafe[i];

        if (cur.first == next.first || cur.second == next.second){

            num[order++] = next;
            cur = next;

            while (!s.empty()){
                num[order++] = s.top();
                cur = s.top();
                s.pop();
            }
        }
        else
            s.push(next);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> T; 

    while (T--){
        cin >> n;

        for (int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            cafe.push_back({x, y});
        }

        //sort
        sort(cafe.begin(), cafe.end());

        //solve
        solve();

        //output
        cin >> m;

        for (int i = 0; i < m; i++){
            int j;
            cin >> j;
            cout << num[j].first << " " << num[j].second << "\n";
        }

        //init
        cafe.clear();
    }
}
