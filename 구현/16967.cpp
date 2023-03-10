#include <iostream>

using namespace std;

int h, w, x, y;
int A[300][300], B[600][600];

void solve(){
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            A[i][j] = B[i][j];

    for(int i = x; i < h; i++)
        for(int j = y; j < w; j++)
            A[i][j] = A[i][j] - A[i - x][j - y];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
	cin >> h >> w >> x >> y;
	for(int i = 0; i < h + x; i++)
		for(int j = 0; j < w + y; j++)
			cin >> B[i][j];

    //solve array A
    solve();

    //output
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
}
