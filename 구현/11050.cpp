#include <iostream>
#include <cmath>

using namespace std;

int n, k;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    int answer=1;

    // n!/(n-k)!
    for(int i=0; i<k; i++)
        answer*=n-i;
    
    // answer/k!
    for(int i=0; i<k; i++)
        answer/=k-i;
    
    cout << answer;
}
