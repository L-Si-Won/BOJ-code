#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
char map[1000][1000];
pair<int, int> r;
int dp[1000][1000];
bool visit[1000][1000];
bool exit_flag;
int dx[] = {1, 0, -1};

void bfs(){
    queue<pair<int, int>> q;
    q.push(r);
    visit[r.first][r.second] = true;

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (map[x][y] == 'O')
            exit_flag = true;

        for(int i = 0; i < 3; i++){
            int nx = x + dx[i];
            int ny = y + 1;

            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (map[nx][ny] != '#'){
                    if (map[nx][ny] == 'C'){
                        if (visit[nx][ny] == false || dp[nx][ny] < dp[x][y] + 1){
                            visit[nx][ny] = true;
                            dp[nx][ny] = dp[x][y] + 1;
                            q.push({nx, ny});
                        }
                    }
                    else{
                        if (visit[nx][ny] == false || dp[nx][ny] < dp[x][y]){
                            visit[nx][ny] = true;
                            dp[nx][ny] = dp[x][y];
                            q.push({nx, ny});
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

    //input
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++){
            map[i][j] = temp[j];

            if (map[i][j] == 'R')
                r = {i, j};
        }
    }

    bfs();

    int answer = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (map[i][j] == 'O'){
                answer = max(answer, dp[i][j]);
            }
        }
    }

    if (exit_flag == false)
        cout << -1;
    else
        cout << answer;
}
