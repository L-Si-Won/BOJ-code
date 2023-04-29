#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b, c;
	cin >> a >> b >> c;

	if (a == b && b == c)
		cout << 10000 + a * 1000;
	else if (a == b && b != c)
		cout << 1000 + a * 100;
	else if (a == c && a != b)
		cout << 1000 + a * 100;
	else if (b == c && b != a)
		cout << 1000 + b * 100;
	else if (a != b && b != c && c != a)
		cout << max(a, max(b, c)) * 100;
}
