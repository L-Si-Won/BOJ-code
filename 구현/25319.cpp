#include <iostream>
#include <vector>

using namespace std;

int n, m, s_len, c = 2e9, l;
string s, l_str;
vector<pair<int, int>> map[26];
vector<int> cnt(26);

void move(pair<int, int> cur, pair<int, int> next){
    int cx = cur.first;
    int cy = cur.second;
    int nx = next.first;
    int ny = next.second;

    int dx = cx - nx;
    int dy = cy - ny;

    char x_cmd = dx > 0 ? 'U' : 'D';
    char y_cmd = dy > 0 ? 'L' : 'R';

    for (int i = 0; i < abs(dx); i++)
        l_str += x_cmd;
    for (int i = 0; i < abs(dy); i++)
        l_str += y_cmd;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> m >> s_len;
    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;

        for(int j = 0; j < m; j++)
            map[temp[j] - 'a'].push_back({i, j});
    }
    cin >> s;

    //the number of alphabet to need
    for (int i = 0; i < s_len; i++)
        cnt[s[i] - 'a']++;

    //c as big as possible
    for (int i = 0; i < s_len; i++)
        c = min(c, (int)map[s[i] - 'a'].size() / cnt[s[i] - 'a']);

    //game start
    pair<int, int> cur = {0, 0};
    for (int i = 0; i < c; i++){
        for (int j = 0; j < s_len; j++){
            pair<int, int> next = map[s[j] - 'a'].back();
            map[s[j] - 'a'].pop_back();
            move(cur, next);
            l_str += 'P';
            cur = next;
        }
    }
    move(cur, {n - 1, m - 1});

    //output
    l = l_str.length();
    cout << c << " " << l << "\n";
    cout << l_str;
}
