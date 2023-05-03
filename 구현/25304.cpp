#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, n, a, b, sum = 0;
	cin >> x >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		sum += a * b;
	}

	if (x == sum)
		cout << "Yes";
	else
		cout << "No";
}
