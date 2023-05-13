#include <iostream>

using namespace std;

int k, g[14], max_sum;
bool x[2600000];

void dfs(int idx, int sum){
    
    if (idx == k + 1){
        if (sum > 0)
            x[sum] = true;
        return;
    }

    //더하거나
    dfs(idx + 1, sum + g[idx]);
    //고려안하거나
    dfs(idx + 1, sum);
    //빼거나
    dfs(idx + 1, sum - g[idx]);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> k;
    for (int i = 1; i <= k; i++){
        cin >> g[i];
        max_sum += g[i];
    }

    //dfs
    dfs(1, 0);

    //output
    int answer = 0;
    for (int i = 1; i <= max_sum; i++)
        if (x[i] == false)
            answer++;
    cout << answer;
}
