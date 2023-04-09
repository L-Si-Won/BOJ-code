#include <iostream>

using namespace std;

string s1, s2;
int dp[1001][1001];

void LCS(){
    int len1 = s1.length();
    int len2 = s2.length();

    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> s1 >> s2;

    //LCS
    LCS();

    //output
    cout << dp[s1.length()][s2.length()];
}
