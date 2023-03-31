#include <iostream>

using namespace std;

int n, answer;
int chart[100000];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> chart[i];

    //calculate
    int max_price = chart[n - 1];
    for(int i = n - 2; i >= 0; i--){
        if (chart[i] < max_price)
            answer += max_price - chart[i];
        else
            max_price = chart[i];
    }

    //output
    cout << answer;
}
