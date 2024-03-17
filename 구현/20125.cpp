#include <iostream>

using namespace std;

int n, la, ra, ll, rl, waist;
char map[1001][1001];
pair<int, int> heart;
bool heart_flag;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++){
            map[i][j] = s[j - 1];
            if (heart_flag == false && map[i][j] == '*'){
                heart = {i + 1, j};
                heart_flag = true;
            }
        }
    }

    //left arm
    for (int i = heart.second - 1; i > 0; i--)
        if (map[heart.first][i] == '*')
            la++;
    
    //right arm
    for (int i = heart.second + 1; i <= n; i++)
        if (map[heart.first][i] == '*')
            ra++;

    //waist
    for (int i = heart.first + 1; i <= n; i++)
        if (map[i][heart.second] == '*')
            waist++;
    
    //left leg
    for (int i = heart.first + waist + 1; i <= n; i++)
        if (map[i][heart.second - 1] == '*')
            ll++;

    //right leg
    for (int i = heart.first + waist + 1; i <= n; i++)
        if (map[i][heart.second + 1] == '*')
            rl++;

    //output
    cout << heart.first << " " << heart.second << "\n";
    cout << la << " ";
    cout << ra << " ";
    cout << waist << " ";
    cout << ll << " ";
    cout << rl << "\n";
}
