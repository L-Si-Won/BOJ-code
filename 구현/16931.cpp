#include <iostream>

using namespace std;

int n, m, arr[100][100], answer;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int count_area(int x, int y){
	if (arr[x][y] == 0)
		return 0;

	int cnt = 0;

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m){
			if (arr[nx][ny] == 0) //옆칸의 블럭이 0개인 경우
				cnt += arr[x][y];
			else //옆칸의 높이보다 높은 경우
				if (arr[x][y] > arr[nx][ny])
					cnt += arr[x][y] - arr[nx][ny];
		}
		else //옆칸이 종이 밖일 경우
			cnt += arr[x][y];
	}
	cnt += 2; //맨 윗면과 맨 아랫면

	return cnt;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
    cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];

	//count area
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			answer += count_area(i, j);
	
	//output
	cout << answer;
}
