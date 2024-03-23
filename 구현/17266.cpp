#include <iostream>

using namespace std;

int n, m, s, e, Max;
bool road[100'001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        road[x] = true;

        if (i == 0)
            s = x;
        if (i == m - 1)
            e = x;
    }

    //check s ~ e
    int pre = s;
    for (int i = s + 1; i <= e; i++){
        if (road[i] == true){
            Max = max(Max, i - pre);
            pre = i;
        }
    }
    Max = Max % 2 == 0 ? Max / 2 : Max / 2 + 1;

    //find max range
    Max = max(Max, s);
    Max = max(Max, n - e);

    //output
    cout << Max;
}
