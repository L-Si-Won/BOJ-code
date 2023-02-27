#include <iostream>

using namespace std;

int n, m, k, arr[10][10], answer = -40001;
bool visit[10][10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int cnt, int sum){
    if (cnt == k){
        answer = max(answer, sum);
        return ;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (visit[i][j] == false){
                bool flag = true;

                for(int l = 0; l < 4; l++){
                    int adj_i = i + dx[l];
                    int adj_j = j + dy[l];

                    if (adj_i >= 0 && adj_i < n && adj_j >= 0 && adj_j < m)
                        if (visit[adj_i][adj_j] == true)
                            flag = false;
                }

                if (flag == true){
                    visit[i][j] = true;
                    dfs(cnt + 1, sum + arr[i][j]);
                    visit[i][j] = false;
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
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    //dfs
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visit[i][j] = true;
            dfs(1, arr[i][j]);
            visit[i][j] = false;
        }
    }

    //output
    cout << answer;
}
