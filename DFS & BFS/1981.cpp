#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, arr[100][100];
int min_value = 201, max_value = -1;
bool visit[100][100];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check_case(int diff){
    for(int i = min_value; i <= max_value; i++){
        memset(visit, true, sizeof(visit));

        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                if (arr[j][k] >= i && arr[j][k] <= i + diff)
                    visit[j][k] = false;
        
        queue<pair<int, int>> q;
        if (visit[0][0] == false){
            q.push({0, 0});
            visit[0][0] = true;
        }

        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == n - 1 && y == n - 1)
                return true;

            for (int j = 0; j < 4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n){
                    if (visit[nx][ny] == false){
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            min_value = min(min_value, arr[i][j]);
            max_value = max(max_value, arr[i][j]);
        }
    }

    //min search
    int start = 0;
    int end = max_value - min_value;

    while (start <= end){
        int mid = (start + end) / 2;
        if (check_case(mid) == true)
            end = mid - 1;
        else
            start = mid + 1;
    }

    //output
    cout << end + 1;
}
