#include <iostream>
#include <cstring>

using namespace std;

int n, m, r, arr[100][100], temp[100][100];

void arr_cpy(){
	memset(temp, 0, sizeof(temp));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			temp[i][j] = arr[i][j];
	memset(arr, 0, sizeof(arr));
}

void fun1(){
	arr_cpy();

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			arr[i][j] = temp[n - i - 1][j];
}

void fun2(){
	arr_cpy();

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			arr[i][j] = temp[i][m - j - 1];
}

void fun3(){
	arr_cpy();

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			arr[i][j] = temp[n - j - 1][i];
	
	int n_temp = n;
	n = m;
	m = n_temp;
}

void fun4(){
	arr_cpy();

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			arr[i][j] = temp[j][m - i - 1];

	int n_temp = n;
	n = m;
	m = n_temp;
}

void fun5(){
	arr_cpy();

	//4 -> 1
	for(int i = 0; i < n / 2; i++)
		for(int j = 0; j < m / 2; j++)
			arr[i][j] = temp[i + n / 2][j];
	//1 -> 2
	for(int i = 0; i < n / 2; i++)
		for(int j = m / 2; j < m; j++)
			arr[i][j] = temp[i][j - m / 2];
	//2 -> 3
	for(int i = n / 2; i < n; i++)
		for(int j = m / 2; j < m; j++)
			arr[i][j] = temp[i - n / 2][j];
	//3 -> 4
	for(int i = n / 2; i < n; i++)
		for(int j = 0; j < m / 2; j++)
			arr[i][j] = temp[i][j + m / 2];
}

void fun6(){
	arr_cpy();

	//2 -> 1
	for(int i = 0; i < n / 2; i++)
		for(int j = 0; j < m / 2; j++)
			arr[i][j] = temp[i][j + m / 2];
	//3 -> 2
	for(int i = 0; i < n / 2; i++)
		for(int j = m / 2; j < m; j++)
			arr[i][j] = temp[i + n / 2][j];
	//4 -> 3
	for(int i = n / 2; i < n; i++)
		for(int j = m / 2; j < m; j++)
			arr[i][j] = temp[i][j - m / 2];
	//1 -> 4
	for(int i = n / 2; i < n; i++)
		for(int j = 0; j < m / 2; j++)
			arr[i][j] = temp[i - n / 2][j];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
    cin >> n >> m >> r;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> arr[i][j];
	
	//input operator and calculate
	while (r--){
		int order;
		cin >> order;

		if (order == 1)
			fun1();
		if (order == 2)
			fun2();
		if (order == 3)
			fun3();
		if (order == 4)
			fun4();
		if (order == 5)
			fun5();
		if (order == 6)
			fun6();
	}

	//output
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
