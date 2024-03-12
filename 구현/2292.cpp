#include <iostream>

using namespace std;

int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;

    int six = 6, cnt = 0;

    for (int i = 1; i <= 1'000'000'000;){
        if (n <= i)
            break;
        
        cnt++;
        i += six;
        six += 6;
    }

    cout << cnt + 1;
}
