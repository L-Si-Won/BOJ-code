#include <iostream>

using namespace std;

int n, h[100'001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];

    int answer = 0;
    int max_h = 0;
    for(int i = n; i >= 1; i--){
        if (h[i] > max_h){
            max_h = h[i];
            answer++;
        }
    }

    cout << answer;
}
