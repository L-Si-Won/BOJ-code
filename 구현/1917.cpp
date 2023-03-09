#include <iostream>
#include <vector>

using namespace std;

int arr[6][6];
vector<vector<string>> possible_square = {
	{"1000", "1111", "1000"},
	{"0100", "1111", "1000"},
	{"0010", "1111", "1000"},
	{"0001", "1111", "1000"},
	{"0100", "1111", "0100"},
	{"0010", "1111", "0100"},
	{"0011", "0110", "1100"},
	{"0011", "1110", "1000"},
	{"0011", "1110", "0100"},
	{"0011", "1110", "0010"},
	{"00111", "11100"}
};

vector<string> rotate_square(vector<string> v){
	int row = v[0].length();
	int col = v.size();
	vector<string> temp(row);

	for (int i = 0; i < row; i++)
		for (int j = col - 1; j >= 0; j--)
			temp[i] += v[j][i];

	return temp;
}

vector<string> reverse_square(vector<string> v) {
	int row = v.size();
	int col = v[0].length();
	vector<string> temp(v.size());

	for (int i = 0; i < row; i++)
		for (int j = col - 1; j >= 0; j--)
			temp[i] += v[i][j];

	return temp;
}

bool compare_square(int x, int y, vector<string> v){
	for (int i = 0; i < v.size(); i++){
		for (int j = 0; j < v[0].length(); j++) {
			int nx = x + i;
			int ny = y + j;

			if (nx < 0 || nx >= 6 || ny < 0 || ny >= 6)
				return false;
			
			if ((v[i][j] - '0') != arr[nx][ny])
				return false;
		}
	}

	return true; 
}

bool check_square(){
	bool flag = false;

	for(int square = 0; square < 11; square++){
		vector<string> v = possible_square[square];

		for(int reverse = 0; reverse < 2; reverse++){

			for(int rotate = 0; rotate < 4; rotate++){

				for(int i = 0; i < 6; i++)
					for(int j = 0; j < 6; j++)
						flag |= compare_square(i, j, v);

				v = rotate_square(v);
			}

			v = reverse_square(v);
		}
	}

	return flag;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	for(int i = 0; i < 3; i++){

		//input
		for(int j = 0; j < 6; j++)
			for(int k = 0; k < 6; k++)
				cin >> arr[j][k];
		
		//check and ouput
		if (check_square() == true)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
