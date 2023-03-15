#include <iostream>

using namespace std;

int n, l, answer, sum, alcohol[1000000];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
	cin >> n >> l;
	for(int i = 0; i < n; i++)
		cin >> alcohol[i];
	
	//coding test
	for(int i = 0; i < n; i++){
		sum += alcohol[i];
		
		if (i >= l)
			sum -= alcohol[i - l];

		if (sum >= 129 && sum <= 138)
			answer++;
	}

	//output
	cout << answer;
}
