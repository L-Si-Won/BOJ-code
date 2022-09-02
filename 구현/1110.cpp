#include <iostream>

using namespace std;

int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    int origin=n;
    int cnt=0;
    while(1){
        int sum=n/10+n%10;
        n=n%10*10+sum%10;
        cnt++;
        if(n==origin){
            cout << cnt;
            break;
        }
    }
}
