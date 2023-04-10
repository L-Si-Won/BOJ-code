#include <iostream>

using namespace std;

int n, f;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> f;

    //calculate
    n = n / 100 * 100;
    
    for(int i = 0; i < 100; i++){
        if (n % f == 0)
            break;
        n++;
    }

    //output
    printf("%.2d", n % 100);
}
