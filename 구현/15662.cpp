#include <iostream>
#include <cstring>

using namespace std;

int t, k, gear[1000][8], cnt;

/*
	gear[i][2] : 오른쪽 극
	gear[i][6] : 왼쪽 극
*/

void real_rotate(int a, int b){
	if (b == 1){ //시계방향 회전
		int temp = gear[a][7];
		for(int i = 7; i > 0; i--)
			gear[a][i] = gear[a][i - 1];
		gear[a][0] = temp;
	}
	else if (b == -1){ //반시계방향 회전
		int temp = gear[a][0];
		for(int i = 0; i < 7; i++)
			gear[a][i] = gear[a][i + 1];
		gear[a][7] = temp;
	}
}

void rotate(int a, int b){
	bool is_rotate[1000][2]; //양쪽에 의한 회전 여부
	memset(is_rotate, false, sizeof(is_rotate));

	//회전 여부 확인
	for(int i = 0; i < t - 1; i++)
		if (gear[i][2] != gear[i + 1][6])
			is_rotate[i][1] = true;
	for(int i = t - 1; i >= 0; i--)
		if (gear[i][6] != gear[i - 1][2])
			is_rotate[i][0] = true;

	//주어진 톱니바퀴 회전
	real_rotate(a, b);

	//주어진 톱니바퀴의 오른쪽 회전
	int b_temp = -b;
	for(int i = a + 1; i < t; i++){
		if (is_rotate[i][0] == true){
			real_rotate(i, b_temp);
			b_temp *= -1;
		}
		else
			break;
	}

	//주어진 톱니바퀴의 왼쪽 회전
	b_temp = -b;
	for(int i = a - 1; i >= 0; i--){
		if (is_rotate[i][1] == true){
			real_rotate(i, b_temp);
			b_temp *= -1;
		}
		else break;
	}
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
    cin >> t;
	for(int i = 0; i < t; i++){
		string s;
		cin >> s;
		for(int j = 0; j < 8; j++)
			gear[i][j] = s[j] - '0';
	}
	cin >> k;

	//rotate
	while(k--){
		int a, b;
		cin >> a >> b;

		rotate(a - 1, b);
	}

	//output
	for(int i = 0; i < t; i++)
		if (gear[i][0] == 1)
			cnt++;
	cout << cnt;
}
