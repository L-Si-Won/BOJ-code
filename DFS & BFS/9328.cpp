#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int tc, h, w, answer;
char map[102][102];
bool key[26];
bool visit[102][102];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void init(){
    memset(map, 0, sizeof(map));
    memset(visit, false, sizeof(visit));
    memset(key, false, sizeof(key));
    answer = 0;
}

void bfs(){
    queue<pair<int, int>> q;
    queue<pair<int, int>> cant_open[26];
    q.push({0, 0});
    visit[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx <= h + 1 && ny >= 0 && ny <= w + 1){
                if (visit[nx][ny] == false && map[nx][ny] != '*'){
                    if (map[nx][ny] == '.'){
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                    else if (map[nx][ny] == '$'){
                        answer++;
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                    else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'Z'){
                        if (key[map[nx][ny] - 'A'] == true){
                            visit[nx][ny] = true;
                            q.push({nx, ny});
                        }
                        else
                            cant_open[map[nx][ny] - 'A'].push({nx, ny});
                    }
                    else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'z'){
                        visit[nx][ny] = true;
                        q.push({nx, ny});

                        //add key
                        key[map[nx][ny] - 'a'] = true;
                        
                        while(!cant_open[map[nx][ny] - 'a'].empty()){
                            int door_x = cant_open[map[nx][ny] - 'a'].front().first;
                            int door_y = cant_open[map[nx][ny] - 'a'].front().second;
                            cant_open[map[nx][ny] - 'a'].pop();

                            visit[door_x][door_y] = true;
                            q.push({door_x, door_y});
                        }
                    }
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input testcase
    cin >> tc;

    while (tc--){
        init();

        //input h, w
        cin >> h >> w;

        //input map
        string temp;
        for(int i = 1; i <= h; i++){
            cin >> temp;

            for(int j = 0; j < w; j++)
                map[i][j + 1] = temp[j];
        }

        //make outline
        for(int i = 0; i <= h + 1; i++)
            for(int j = 0; j <= w + 1; j++)
                if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
                    map[i][j] = '.';

        //input key
        cin >> temp;
        if (temp[0] != '0')
            for(int j = 0; j < temp.length(); j++)
                key[temp[j] - 'a'] = true;

        //bfs
        bfs();

        //output
        cout << answer << "\n";
    }
}
