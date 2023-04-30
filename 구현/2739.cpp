#include <iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 1; i <= 9; i++)
        printf("%d * %d = %d\n", n, i, n * i);
}
