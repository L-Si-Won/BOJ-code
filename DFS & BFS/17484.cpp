#include <iostream>
#include <queue>

using namespace std;

int n, m, map[8][7], answer = 2e9;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    //bfs
    queue<pair<pair<int, int>, pair<int, int>>> q; //{{point}, {dir, cost}}
    for (int i = 1; i <= m; i++)
        q.push({{0, i}, {-1, 0}});
    
    while (!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if (x == n + 1){
            answer = min(answer, cost);
            continue;
        }

        for (int i = 0; i < 3; i++){ //dir : 0=left, 1=middle, 2=right
            if (i == dir)
                continue;
            
            if (i == 0 && y - 1 >= 1)
                q.push({{x + 1, y - 1}, {i, cost + map[x + 1][y - 1]}});
            else if (i == 1)
                q.push({{x + 1, y}, {i, cost + map[x + 1][y]}});
            else if (i == 2 && y + 1 <= m)
                q.push({{x + 1, y + 1}, {i, cost + map[x + 1][y + 1]}});
        }
    }

    cout << answer;
}
