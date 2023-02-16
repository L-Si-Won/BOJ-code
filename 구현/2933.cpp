#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int r, c, n, h;
char cave[100][100];
bool left_flag = true;
bool visit[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void crash(){
    if (left_flag == true){
        left_flag = false;
        for(int i = 0; i < c; i++){
            if (cave[r-h][i] == 'x'){
                cave[r-h][i] = '.';
                break;
            }
        }
    }
    else{
        left_flag = true;
        for(int i = c - 1; i >= 0; i--){
            if (cave[r-h][i] == 'x'){
                cave[r-h][i] = '.';
                break;
            }
        }
    }
}

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c){
                if (cave[nx][ny] == 'x' && visit[nx][ny] == false){
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

void check_air(){
    memset(visit, false, sizeof(visit));

    for(int i = 0; i < c; i++)
        if (cave[r - 1][i] == 'x' && visit[r - 1][i] == false)
            bfs(r - 1, i);
}

int cal_fall_height(int x, int y){
    int temp_fall_height = 0;

    for(int i = x + 1; i < r; i++){
        if (cave[i][y] == 'x'){
            if (visit[i][y] == true)
                return temp_fall_height;
            else if (visit[i][y] == false)
                return 2e9;
        }
        else if (cave[i][y] == '.')
            temp_fall_height++;
    }
    return temp_fall_height;
}

void fall(){
    int fall_height = 2e9;

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if (cave[i][j] == 'x' && visit[i][j] == false)
                fall_height = min(fall_height, cal_fall_height(i, j));

    for(int i = r - 1; i >= 0; i--){
        for(int j = c - 1; j >= 0; j--){
            if (cave[i][j] == 'x' && visit[i][j] == false){
                cave[i][j] = '.';
                cave[i + fall_height][j] = 'x';
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        for(int j = 0; j < c; j++)
            cave[i][j] = s[j];
    }

    //crash and fall
    cin >> n;
    while (n--){
        cin >> h;
        crash();
        check_air();
        fall();
        
    }

    //output
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c ; j++)
            cout << cave[i][j];
        cout << "\n";
    }
}
