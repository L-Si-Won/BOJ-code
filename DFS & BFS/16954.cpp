#include <iostream>
#include <queue>

using namespace std;

char map[8][8];
int dx[] = {0, 1, 0 ,-1, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, 0, -1, 1, -1, 1, -1};

void move_wall(){
    for(int i = 7; i >= 0; i--){
        for(int j = 7; j >= 0; j--){
            if (i + 1 < 8 && map[i][j] == '#'){
                map[i][j] = '.';
                map[i + 1][j] = '#';
            }
            else if (i + 1 == 8 && map[i][j] == '#')
                map[i][j] = '.';
        }
    }
}

bool bfs(){
    //{좌표, 움직인 횟수}
    queue<pair<pair<int, int>, int>> q;
    q.push({{7, 0}, 0});
    int move_cnt = 0;

    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (x == 0 && y == 7)
            return true;

        if (move_cnt < cnt){
            move_wall();
            move_cnt++;
        }

        if (map[x][y] == '#')
            continue;

        for(int i = 0; i < 9; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
                if (map[nx][ny] == '.')
                    q.push({{nx, ny}, cnt + 1});
        }
    }

    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    for(int i = 0; i < 8; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 8; j++)
            map[i][j] = s[j];
    }

    //bfs and ouput
    if (bfs() == true)
        cout << 1;
    else
        cout << 0;
}
