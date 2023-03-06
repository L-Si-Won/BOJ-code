#include <iostream>
#include <cstring>

using namespace std;

int n, x, y, d, g;
bool arr[101][101];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void make_dragonCurve(){
	bool temp1[101][101];
	bool temp2[101][101];
	memset(temp1, false, sizeof(temp1));
	memset(temp2, false, sizeof(temp2));

	int end_x = x + dx[d];
	int end_y = y + dy[d];
	temp1[y][x] = true;
	temp1[end_y][end_x] = true;
	copy(&temp1[0][0], &temp1[0][0] + 101 * 101, &temp2[0][0]);

	while (g--){
		int temp_x, temp_y;
		for(int i = 0; i < 101; i++){
			for(int j = 0; j < 101; j++){
				if (temp2[i][j] == true){
					int cx = j;
					int cy = i;

					if (cx == end_x && cy == end_y)
						continue;

					int inc_x = end_x - cx;
					int inc_y = end_y - cy;

					int nx = end_x + inc_y;
					int ny = end_y - inc_x;

					temp1[ny][nx] = true;

					if (cx == x && cy == y){
						temp_x = nx;
						temp_y = ny;
					}
				}
			}
		}
		end_x = temp_x;
		end_y = temp_y;
		copy(&temp1[0][0], &temp1[0][0] + 101 * 101, &temp2[0][0]);
	}

	for(int i = 0; i < 101; i++)
		for(int j = 0; j < 101; j++)
			if (temp1[i][j] == true)
				arr[i][j] = true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> d >> g;
		make_dragonCurve();
	}

	//output
	int cnt = 0;
	for(int i = 0; i < 101; i++){
		for(int j = 0; j < 101; j++){
			if (arr[i][j] == true){
				int flag = 0;
			
				if (i + 1 < 101 && j + 1 < 101){
					if (arr[i + 1][j] == true)
						flag++;
					if (arr[i][j + 1] == true)
						flag++;
					if (arr[i + 1][j + 1] == true)
						flag++;
				}

				if (flag == 3)
					cnt++;
			}
		}
	}
	cout << cnt;
}
