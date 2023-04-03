#include <iostream>

using namespace std;

int n, arr[129][129], white, blue;

void devide(int x1, int y1, int x2, int y2){
    bool flag = true;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if (i >= x1 && i <= x2 && j >= y1 && j <= y2)
                if (arr[x1][y1] != arr[i][j])
                    flag = false;

    if (flag == true){
        if (arr[x1][y1] == 0)
            white++;
        else
            blue++;
        return;
    }

    int x_mid = (x1 + x2) / 2;
    int y_mid = (y1 + y2) / 2;
    devide(x1, y1, x_mid, y_mid);
    devide(x_mid + 1, y1, x2, y_mid);
    devide(x1, y_mid + 1, x_mid, y2);
    devide(x_mid + 1, y_mid + 1, x2, y2);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];

    //devide
    devide(1, 1, n, n);

    //output
    cout << white << "\n" << blue;
}
