#include <iostream>
#include <cstring>

using namespace std;

int n, w;
pair<int, int> event[1001];
int dp[1001][1001];

int dfs(int p1, int p2){

	//last event
	if (p1 == w || p2 == w)
		return 0;

	//already calculate
	if (dp[p1][p2] != -1)
		return dp[p1][p2];

	int next = max(p1, p2) + 1;

	int dist1, dist2;

	if (p1 == 0)
		dist1 = abs(1 - event[next].first) + abs(1 - event[next].second);
	else
		dist1 = abs(event[p1].first - event[next].first) + abs(event[p1].second - event[next].second);

	if (p2 == 0)
		dist2 = (n - event[next].first) + (n - event[next].second);
	else
		dist2 = abs(event[p2].first - event[next].first) + abs(event[p2].second - event[next].second);

	int res1 = dfs(next, p2) + dist1;
	int res2 = dfs(p1, next) + dist2;

	dp[p1][p2] = min(res1, res2);

	return dp[p1][p2];
}

void print_order(int p1, int p2){

	if (p1 == w || p2 == w)
		return ;

	int next = max(p1, p2) + 1;

	int dist1, dist2;

	if (p1 == 0)
		dist1 = abs(1 - event[next].first) + abs(1 - event[next].second);
	else
		dist1 = abs(event[p1].first - event[next].first) + abs(event[p1].second - event[next].second);

	if (p2 == 0)
		dist2 = (n - event[next].first) + (n - event[next].second);
	else
		dist2 = abs(event[p2].first - event[next].first) + abs(event[p2].second - event[next].second);

	int res1 = dp[next][p2] + dist1;
	int res2 = dp[p1][next] + dist2;

	if (res1 < res2){
		cout << 1 << "\n";
		print_order(next, p2);
	}
	else{
		cout << 2 << "\n";
		print_order(p1, next);
	}
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//input
	cin >> n >> w;
	for(int i = 1; i <= w; i++)
		cin >> event[i].first >> event[i].second;

	memset(dp, -1, sizeof(dp));

	//calculate min distance and output
	cout << dfs(0, 0) << "\n";
	print_order(0, 0);
}
