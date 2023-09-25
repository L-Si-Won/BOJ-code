#include <iostream>

using namespace std;

int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    //calculate
    int answer = 1;

    for (int i = 0; i < n / 2; i++)
        answer = (answer * 2) % 16769023;
    
    if (n % 2 == 1)
        answer = (answer * 2) % 16769023;

    //output
    cout << answer;
}
