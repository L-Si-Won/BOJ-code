#include <iostream>

using namespace std;

int n, m, r, arr[300][300];

void rotate(){
	int rotate_square_cnt = min(n, m) / 2;
	
	//i는 바깥쪽 사각형부터의 번호, i=0 -> 가장 바깥쪽 사각형
	for(int i = 0; i < rotate_square_cnt; i++){

        //각 사각형 별 회전할 횟수
        int rotate_cnt = r % (((n - i * 2) + (m - i * 2)) * 2 - 4);

        for(int k = 0; k < rotate_cnt; k++){
            int first_element = arr[i][i];

		    //upper side
		    for(int j = i; j < m - i - 1; j++)
		    	arr[i][j] = arr[i][j + 1];
    
		    //right side
		    for(int j = i; j < n - i - 1; j++)
		    	arr[j][m - i - 1] = arr[j + 1][m - i - 1];
    
		    //lower side
		    for(int j = m - i - 1; j > i; j--)
		    	arr[n - i - 1][j] = arr[n - i - 1][j - 1];
    
		    //left side
		    for(int j = n - i - 1; j > i; j--)
		    	arr[j][i] = arr[j - 1][i];

            arr[i + 1][i] = first_element;
        }
	}
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
	
	//rotate
	rotate();

	//output
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}
