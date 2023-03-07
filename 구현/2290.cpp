#include <iostream>

using namespace std;

int s;
string n;
char arr[23][120]; //23 = 2 * 10 + 3, 120 = (10 + 2) * 10

void make_0(int idx){
	for(int i = 1; i < s + 2 - 1; i++){
		arr[0][idx * (s + 2) + i] = '-';
		arr[2 * s + 3 - 1][idx * (s + 2) + i] = '-';
	}

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;
		
		arr[i][idx * (s + 2)] = '|';
		arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
	}
}

void make_1(int idx){
	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;
		
		arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
	}
}

void make_2(int idx){
	for(int i = 1; i < s + 2 - 1; i++){
		arr[0][idx * (s + 2) + i] = '-';
		arr[2 * s + 3 - 1][idx * (s + 2) + i] = '-';
		arr[(2 * s + 3) / 2][idx * (s + 2) + i] = '-';
	}

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;
		
		if (i < (2 * s + 3) / 2)
			arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
		else
			arr[i][idx * (s + 2)] = '|';
	}
}

void make_3(int idx){
	for(int i = 1; i < s + 2 - 1; i++){
		arr[0][idx * (s + 2) + i] = '-';
		arr[2 * s + 3 - 1][idx * (s + 2) + i] = '-';
		arr[(2 * s + 3) / 2][idx * (s + 2) + i] = '-';
	}

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;
		
		arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
	}
}

void make_4(int idx){
	for(int i = 1; i < s + 2 - 1; i++)
		arr[(2 * s + 3) / 2][idx * (s + 2) + i] = '-';

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;

		if (i < (s * 2 + 3) / 2)
			arr[i][idx * (s + 2)] = '|';
		
		arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
	}
}

void make_5(int idx){
	for(int i = 1; i < s + 2 - 1; i++){
		arr[0][idx * (s + 2) + i] = '-';
		arr[2 * s + 3 - 1][idx * (s + 2) + i] = '-';
		arr[(2 * s + 3) / 2][idx * (s + 2) + i] = '-';
	}

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;

		if (i < (s * 2 + 3) / 2)
			arr[i][idx * (s + 2)] = '|';
		else
			arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
	}
}

void make_6(int idx){
	for(int i = 1; i < s + 2 - 1; i++){
		arr[0][idx * (s + 2) + i] = '-';
		arr[2 * s + 3 - 1][idx * (s + 2) + i] = '-';
		arr[(2 * s + 3) / 2][idx * (s + 2) + i] = '-';
	}

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;

		if (i > (s * 2 + 3) / 2)
			arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
			
		arr[i][idx * (s + 2)] = '|';
	}
}

void make_7(int idx){
	for(int i = 1; i < s + 2 - 1; i++)
		arr[0][idx * (s + 2) + i] = '-';

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;
		
		arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
	}
}

void make_8(int idx){
	for(int i = 1; i < s + 2 - 1; i++){
		arr[0][idx * (s + 2) + i] = '-';
		arr[2 * s + 3 - 1][idx * (s + 2) + i] = '-';
		arr[(2 * s + 3) / 2][idx * (s + 2) + i] = '-';
	}

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;
		
		arr[i][idx * (s + 2)] = '|';
		arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
	}
}

void make_9(int idx){
	for(int i = 1; i < s + 2 - 1; i++){
		arr[0][idx * (s + 2) + i] = '-';
		arr[2 * s + 3 - 1][idx * (s + 2) + i] = '-';
		arr[(2 * s + 3) / 2][idx * (s + 2) + i] = '-';
	}

	for(int i = 0; i < 2 * s + 3; i++){
		if (i == 0 || i == 2 * s + 3 - 1 || i == (2 * s + 3) / 2)
			continue;
		
		if (i < (s * 2 + 3) / 2)
			arr[i][idx * (s + 2)] = '|';

		arr[i][idx * (s + 2) + (s + 2) - 1] = '|';
	}
}

void make_num(){
	for(int i = 0; i < n.length(); i++){
		if (n[i] == '0')
			make_0(i);
		if (n[i] == '1')
			make_1(i);
		if (n[i] == '2')
			make_2(i);
		if (n[i] == '3')
			make_3(i);
		if (n[i] == '4')
			make_4(i);
		if (n[i] == '5')
			make_5(i);
		if (n[i] == '6')
			make_6(i);
		if (n[i] == '7')
			make_7(i);
		if (n[i] == '8')
			make_8(i);
		if (n[i] == '9')
			make_9(i);
	}
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
    cin >> s >> n;

	//make num
	for(int i = 0; i < 23; i++)
		for(int j = 0; j < 120; j++)
			arr[i][j] = ' ';
	make_num();

	//output
	for(int i = 0; i < 2 * s + 3; i++){
		for(int j = 0; j < (s + 2) * n.length(); j++){
			cout << arr[i][j];

			if ((j + 1) % (s + 2) == 0 && j != (s + 2) * n.length() - 1) //숫자 사이 공백
				cout << " ";
		}
		cout << "\n";
	}
}
