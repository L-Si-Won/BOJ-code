#include <iostream>
#include <queue>
#define INF 2e9

using namespace std;

int n;
char home[50][50];
pair<int, int> door1 = {-1, -1}, door2;
int mirror[50][50];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(){
    //{{좌표}, {거울 개수, 방향}}
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({door1, {0, -1}});
    mirror[door1.first][door1.second] = 0;
    
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int mir = q.front().second.first;
        int dir = q.front().second.second;
        q.pop();

        if (x == door2.first && y == door2.second)
            continue;

        //0, 1, 2, 3 => 상, 하, 우, 좌
        if (dir == 0 || dir == 1 || dir == -1){
            int nx, ny;
            //우로 이동
            nx = x + dx[2];
            ny = y + dy[2];
            while (nx >= 0 && nx < n && ny >= 0 && ny < n){
                if (home[nx][ny] == '!'){
                    if (mir + 1 <= mirror[nx][ny]){
                        mirror[nx][ny] = mir + 1;
                        q.push({{nx, ny}, {mir + 1, 2}});
                    }
                }
                else if (home[nx][ny] == '#'){
                    if (mir <= mirror[nx][ny]){
                        mirror[nx][ny] = mir;
                        q.push({{nx, ny}, {mir, 2}});
                    }
                    break;
                }
                else if (home[nx][ny] == '*')
                    break;
                nx += dx[2];
                ny += dy[2];
            }
            //좌로 이동
            nx = x + dx[3];
            ny = y + dy[3];
            while (nx >= 0 && nx < n && ny >= 0 && ny < n){
                if (home[nx][ny] == '!'){
                    if (mir + 1 <= mirror[nx][ny]){
                        mirror[nx][ny] = mir + 1;
                        q.push({{nx, ny}, {mir + 1, 3}});
                    }
                }
                else if (home[nx][ny] == '#'){
                    if (mir <= mirror[nx][ny]){
                        mirror[nx][ny] = mir;
                        q.push({{nx, ny}, {mir, 3}});
                    }
                    break;
                }
                else if (home[nx][ny] == '*')
                    break;
                nx += dx[3];
                ny += dy[3];
            }
        }
        if (dir == 2 || dir == 3 || dir == -1){
            int nx, ny;
            //상으로 이동
            nx = x + dx[0];
            ny = y + dy[0];
            while (nx >= 0 && nx < n && ny >= 0 && ny < n){
                if (home[nx][ny] == '!'){
                    if (mir + 1 <= mirror[nx][ny]){
                        mirror[nx][ny] = mir + 1;
                        q.push({{nx, ny}, {mir + 1, 0}});
                    }
                }
                else if (home[nx][ny] == '#'){
                    if (mir <= mirror[nx][ny]){
                        mirror[nx][ny] = mir;
                        q.push({{nx, ny}, {mir, 0}});
                    }
                    break;
                }
                else if (home[nx][ny] == '*')
                    break;
                nx += dx[0];
                ny += dy[0];
            }
            //하로 이동
            nx = x + dx[1];
            ny = y + dy[1];
            while (nx >= 0 && nx < n && ny >= 0 && ny < n){
                if (home[nx][ny] == '!'){
                    if (mir + 1 <= mirror[nx][ny]){
                        mirror[nx][ny] = mir + 1;
                        q.push({{nx, ny}, {mir + 1, 1}});
                    }
                }
                else if (home[nx][ny] == '#'){
                    if (mir <= mirror[nx][ny]){
                        mirror[nx][ny] = mir;
                        q.push({{nx, ny}, {mir, 1}});
                    }
                    break;
                }
                else if (home[nx][ny] == '*')
                    break;
                nx += dx[1];
                ny += dy[1];
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            home[i][j] = s[j];
            mirror[i][j] = INF;
            if (home[i][j] == '#' && door1.first == -1)
                door1 = {i, j};
            else if (home[i][j] == '#' && door1.second != -1)
                door2 = {i, j};
        }
    }

    //bfs
    bfs();

    //output
    cout << mirror[door2.first][door2.second];
}
