#include <iostream>

using namespace std;

int h, w, n, m;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> h >> w >> n >> m;

    cout << (h / (n + 1) + (h % (n + 1) != 0)) * (w / (m + 1) + (w % (m + 1) != 0));
}
