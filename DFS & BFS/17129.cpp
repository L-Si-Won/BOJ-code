#include <iostream>
#include <queue>

using namespace std;

int n, m, a[3000][3000];
pair<int, int> start;
bool visit[3000][3000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(){
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    visit[start.first][start.second] = true;

    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int d = q.front().second;
        q.pop();

        if (a[x][y] == 3 || a[x][y] == 4 || a[x][y] == 5)
            return d;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (visit[nx][ny] == false && a[nx][ny] != 1){
                    visit[nx][ny] = true;
                    q.push({{nx, ny}, d + 1});
                }
            }
        }
    }

    return -1;
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
            a[i][j] = temp[j] - '0';

            if (a[i][j] == 2)
                start = {i, j};
        }
    }

    int answer = bfs();

    if (answer == -1)
        cout << "NIE";
    else
        cout << "TAK\n" << answer;
}
