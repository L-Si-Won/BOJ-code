#include <iostream>

using namespace std;

int n, num, Max, Min;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> num;
    Max = num;
    Min = num;

    for (int i = 1; i < n; i++){
        cin >> num;
        Max = max(Max, num);
        Min = min(Min, num);
    }

    cout << Min << " " << Max << "\n";
}
