#include <iostream>

using namespace std;

int arr[9][9];

bool line_check(int x, int y){
    for(int i = 0; i < 9; i++){
        if (i != x && arr[x][y] == arr[i][y])
            return false;
        if (i != y && arr[x][y] == arr[x][i])
            return false;
    }
    return true;
}

bool square_check(int x, int y){
    int start_x = x - x % 3;
    int start_y = y - y % 3;

    for(int i = start_x; i <= start_x + 2; i++)
        for(int j = start_y; j <= start_y + 2; j++)
            if (i != x || j != y)
                if (arr[i][j] == arr[x][y])
                    return false;

    return true;
}

void dfs(int x, int y){
    if (x == 9){ //output
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++)
                cout << arr[i][j];
            cout << "\n";
        }
        exit(0);
    }

    if (arr[x][y] == 0){
        for(int i = 1; i <= 9; i++){
            arr[x][y] = i;
            if (line_check(x, y) == true && square_check(x, y) == true){
                int nx = x;
                int ny = y + 1;
                if (ny == 9){
                    ny = 0;
                    nx++;
                }
                dfs(nx, ny);
            }
        }
        arr[x][y] = 0;
    }
    else{
        int nx = x;
        int ny = y + 1;
        if (ny == 9){
            ny = 0;
            nx++;
        }
        dfs(nx, ny);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    for(int i = 0; i < 9; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 9; j++)
            arr[i][j] = s[j] - '0';
    }

    //back tracking
    dfs(0, 0);
}
