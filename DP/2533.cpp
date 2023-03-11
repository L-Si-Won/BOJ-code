#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v[1000001];
int dp[1000001][2];
bool visit[1000001];

void dfs(int cur){
	visit[cur] = true;
	dp[cur][0] = 1;

	for(int i = 0; i < v[cur].size(); i++){
		int child = v[cur][i];

		if (visit[child] == true)
			continue;
		
		dfs(child);

		dp[cur][1] += dp[child][0];
		dp[cur][0] += min(dp[child][1], dp[child][0]);
	}
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	//dfs
	dfs(1);

	//output
	cout << min(dp[1][0], dp[1][1]);
}
