#include <iostream>
#include <vector>

using namespace std;

int t, n, k, w;
vector<int> v[1001];
int build_time[1001];
int dp[1001];

void init(){
    for(int i = 0; i < 1001; i++){
        v[i].clear();
        build_time[i] = false;
        dp[i] = -1;
    }
}

int cal_time(int cur){
    if (dp[cur] != -1)
        return dp[cur];

    int result = build_time[cur];

    for(int i = 0; i < v[cur].size(); i++)
        result = max(result, cal_time(v[cur][i]) + build_time[cur]);

    dp[cur] = result;

    return result;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> t;
    
    while(t--){
        init();

        cin >> n >> k;

        for(int i = 1; i <= n; i++)
            cin >> build_time[i];

        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            v[y].push_back(x);
        }

        cin >> w;

        //calculate time and output
        cout << cal_time(w) << "\n";
    }
}
