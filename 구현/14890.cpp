#include <iostream>

using namespace std;

int n, l, map[100][100], cnt;

bool row_check(int cur){
	bool runway[100];
	for(int i = 0; i < n; i++)
		runway[i] = false;

	for(int i = 0; i < n - 1;){
		if (map[cur][i] == map[cur][i + 1])
			i++;
		else if (map[cur][i] < map[cur][i + 1]){
			//높이 차이가 1인지 확인
			if (map[cur][i + 1] - map[cur][i] > 1)
				return false;

			//경사로 놓을 수 있는지 확인
			if (runway[i] == true)
				return false;
			for(int j = 1; j < l; j++)
				if ((i - j < 0 || map[cur][i] != map[cur][i - j]) || runway[i - j] == true)
					return false;
			
			//경사로 놓기
			for(int j = 0; j < l; j++)
				runway[i - j] = true;
			
			i++;
		}
		else if (map[cur][i] > map[cur][i + 1]){
			//높이 차이가 1인지 확인
			if (map[cur][i] - map[cur][i + 1] > 1)
				return false;
			
			//경사로 놓을 수 있는지 확인
			for(int j = 1; j < l; j++)
				if (i + 1 + j >= n || map[cur][i + 1] != map[cur][i + 1 + j])
					return false;

			//경사로 놓기
			for(int j = 0; j < l; j++)
				runway[i + 1 + j] = true;
			
			//경사로 놓은 만큼 건너뛰기
			i += l;
		}
	}

	return true;
}

bool column_check(int cur){
	bool runway[100];
	for(int i = 0; i < n; i++)
		runway[i] = false;

	for(int i = 0; i < n - 1;){
		if (map[i][cur] == map[i + 1][cur])
			i++;
		else if (map[i][cur] < map[i + 1][cur]){
			//높이 차이가 1인지 확인
			if (map[i + 1][cur] - map[i][cur] > 1)
				return false;

			//경사로 놓을 수 있는지 확인
			if (runway[i] == true)
				return false;
			for(int j = 1; j < l; j++)
				if ((i - j < 0 || map[i][cur] != map[i - j][cur]) || runway[i - j] == true)
					return false;
			
			//경사로 놓기
			for(int j = 0; j < l; j++)
				runway[i - j] = true;
			
			i++;
		}
		else if (map[i][cur] > map[i + 1][cur]){
			//높이 차이가 1인지 확인
			if (map[i][cur] - map[i + 1][cur] > 1)
				return false;
			
			//경사로 놓을 수 있는지 확인
			for(int j = 1; j < l; j++)
				if (i + 1 + j >= n || map[i + 1][cur] != map[i + 1 + j][cur])
					return false;

			//경사로 놓기
			for(int j = 0; j < l; j++)
				runway[i + 1 + j] = true;
			
			//경사로 놓은 만큼 건너뛰기
			i += l;
		}
	}

	return true;
}

void road(){
	for(int i = 0; i < n; i++){
		if (row_check(i) == true)
			cnt++;
		if (column_check(i) == true)
			cnt++;
	}
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
    cin >> n >> l;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> map[i][j];

	//count road
	road();

	//output
	cout << cnt;
}
