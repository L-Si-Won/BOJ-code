#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2, answer;
int lcs_len[1001][1001];

void LCS(){
    int l1 = s1.length();
    int l2 = s2.length();

    for(int i = 1; i < l1; i++){
        for(int j = 1; j < l2; j++){
            if (s1[i] == s2[j])
                lcs_len[i][j] = lcs_len[i - 1][j - 1] + 1;
            else
                lcs_len[i][j] = max(lcs_len[i - 1][j], lcs_len[i][j - 1]);
        }
    }

    int x = l1 - 1;
    int y = l2 - 1;
    while(lcs_len[x][y] != 0){
        if (lcs_len[x][y] == lcs_len[x - 1][y])
            x--;
        else if (lcs_len[x][y] == lcs_len[x][y - 1])
            y--;
        else{
            answer += s1[x];
            x--;
            y--;
        }
    }

    reverse(answer.begin(), answer.end());
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;

    //find LCS
    LCS();

    //output
    cout << lcs_len[s1.length() - 1][s2.length() - 1] << "\n" << answer;
}
