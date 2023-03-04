#include <iostream>

using namespace std;

struct dice{
	int over = 0;
	int under = 0;
	int right = 0;
	int left = 0;
	int up = 0;
	int down = 0;
};

int n, m, x, y, k, map[20][20];
dice d;

bool roll_check(int a){
	if (a == 1 && y == m - 1)
		return false;
	if (a == 2 && y == 0)
		return false;
	if (a == 3 && x == 0)
		return false;
	if (a == 4 && x == n - 1)
		return false;
	return true;
}

void num_copy(){
	if (map[x][y] == 0)
		map[x][y] = d.under;
	else{
		d.under = map[x][y];
		map[x][y] = 0;
	}
}

void change1(){
	int temp = d.over;
	d.over = d.left;
	d.left = d.under;
	d.under = d.right;
	d.right = temp;
}

void change2(){
	int temp = d.over;
	d.over = d.right;
	d.right = d.under;
	d.under = d.left;
	d.left = temp;
}

void change3(){
	int temp = d.over;
	d.over = d.down;
	d.down = d.under;
	d.under = d.up;
	d.up = temp;
}

void change4(){
	int temp = d.over;
	d.over = d.up;
	d.up = d.under;
	d.under = d.down;
	d.down = temp;
}

void roll(int a){
	if (a == 1){
		y++;
		change1();
	}
	if (a == 2){
		y--;
		change2();
	}
	if (a == 3){
		x--;
		change3();
	}
	if (a == 4){
		x++;
		change4();
	}
	num_copy();
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m >> x >> y >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> map[i][j];
	
	//roll and output
	while (k--){
		int a;
		cin >> a;

		if (roll_check(a) == false)
			continue;

		roll(a);

		//output
		cout << d.over << "\n";
	}
}
