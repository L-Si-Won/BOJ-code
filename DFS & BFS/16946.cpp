#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m, area_num;
int answer[1000][1000], map[1000][1000], area[1000][1000];
bool visit[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> area_size;

void devide_area(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;
    area[x][y] = area_num;
    int cnt = 1;

    while (!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (map[nx][ny] == 0 && visit[nx][ny] == false){
                    visit[nx][ny] = true;
                    area[nx][ny] = area_num;
                    cnt++;
                    q.push({nx, ny});
                }
            }
        }
    }

    area_size.push_back(cnt);
}

int count_area(int x, int y){
    set<int> area_set;
    int cnt = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m){
            if (map[nx][ny] == 0 && area_set.find(area[nx][ny]) == area_set.end()){
                cnt += area_size[area[nx][ny]];
                area_set.insert(area[nx][ny]);
            }
        }
    }

    return cnt;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++)
            map[i][j] = s[j] - '0';
    }

    //devide area
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (map[i][j] == 0 && visit[i][j] == false){
                devide_area(i, j);
                area_num++;
            }
        }
    }

    //count area's size
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] == 1)
                answer[i][j] = count_area(i, j) % 10;

    //output
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << answer[i][j];
        cout << "\n";
    }
}
