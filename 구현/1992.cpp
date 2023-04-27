#include <iostream>

using namespace std;

int n, arr[64][64];

void compress(int start_x, int start_y, int end_x, int end_y){

    bool flag = true;
    int temp = arr[start_x][start_y];

    //check compression
    for(int i = start_x; i <= end_x; i++){
        for(int j = start_y; j <= end_y; j++){
            if (arr[i][j] != temp){
                flag = false;
                break;
            }
        }
        if (flag == false)
            break;
    }

    //compress
    if (flag == true){
        cout << temp;
        return;
    }

    //if size is 4, can't devide
    if (end_x - start_x == 1){
        cout << "(";
        for(int i = start_x; i <= end_x; i++)
            for(int j = start_y; j <= end_y; j++)
                cout << arr[i][j];
        cout << ")";
        return;
    } 

    //devide
    int mid_x = (start_x + end_x) / 2;
    int mid_y = (start_y + end_y) / 2;
    cout << "(";
    compress(start_x, start_y, mid_x, mid_y);
    compress(start_x, mid_y + 1, mid_x, end_y);
    compress(mid_x + 1, start_y, end_x, mid_y);
    compress(mid_x + 1, mid_y + 1, end_x, end_y);
    cout << ")";
}
    
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;

        for(int j = 0; j < n; j++)
            arr[i][j] = temp[j] - '0';
    }

    //devide and conquer
    compress(0, 0, n - 1, n - 1);
}
