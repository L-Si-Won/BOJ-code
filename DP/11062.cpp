#include <iostream>
#include <cstring>

using namespace std;

int T, N, card[1000], dp[1000][1000];

int game(int left, int right, int turn){
    
    if (left > right)
        return 0;
    if (dp[left][right] != 0)
        return dp[left][right];
    
    if (turn == 1)
        return dp[left][right] = max(card[left] + game(left + 1, right, 0), card[right] + game(left, right - 1, 0));
    else
        return dp[left][right] = min(game(left + 1, right, 1), game(left, right - 1, 1));
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> T;

    while (T--){
        cin >> N;
        for (int i = 0 ; i < N; i++)
            cin >> card[i];

        //dp
        game(0, N - 1, 1);

        //output
        cout << dp[0][N - 1] << "\n";

        memset(dp, 0, sizeof(dp));
    }
}
