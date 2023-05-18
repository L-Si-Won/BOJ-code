#include <iostream>
#include <vector>

using namespace std;

struct employee{
    int r, c, t, cur_t;
    bool work;
};

int b, n, m, arr[100][100], answer;
vector<employee> emp;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void gift_move(){
    
    for (int i = 1; i <= b - 1; i++){
        if (arr[b - 1][i] == 1){
            arr[b - 1][i] = 0;
            arr[b - 1][i - 1] = 1;
        }
    }

    for (int i = b - 2; i >= 0; i--){
        if (arr[i][b - 1] == 1){
            arr[i][b - 1] = 0;
            arr[i + 1][b - 1] = 1;
        }
    }

    for (int i = b - 2; i >= 0; i--){
        if (arr[0][i] == 1){
            arr[0][i] = 0;
            arr[0][i + 1] = 1;
        }
    }
}

void find_emp(int x, int y){

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < b && ny < b){
            if (arr[nx][ny] >= 2 && emp[arr[nx][ny] - 2].work == true){
                emp[arr[nx][ny] - 2].work = false;
                arr[x][y] = 0;
                m--;
                answer++;
                return ;
            }
        }
    }
}

void emp_gift(){
    for (int i = 0; i <= b - 1; i++)
        if (arr[b - 1][i] == 1)
            find_emp(b - 1, i);

    for (int i = b - 2; i >= 0; i--)
        if (arr[i][b - 1] == 1)
            find_emp(i, b - 1);

    for (int i = b - 2; i >= 0; i--)
        if (arr[0][i] == 1)
            find_emp(0, i);
}

void emp_work(){

    for (int i = 0; i < n; i++){
        if (emp[i].work == false){
            emp[i].cur_t--;

            if (emp[i].cur_t == 0){
                emp[i].work = true;
                emp[i].cur_t = emp[i].t;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> b >> n >> m;
    for (int i = 0; i < n; i++){
        int r, c, t;
        cin >> r >> c >> t;
        arr[r][c] = i + 2;
        emp.push_back({r, c, t, t, true});
    }

    //simulation
    int pre_m = m;
    while (m != 0){

        if (arr[b - 1][0] == 1){ //선물폐기
            arr[b - 1][0] = 0;
            m--;
        }

        gift_move(); //한칸씩이동

        if (pre_m > 0){ //시작위치에 올림
            pre_m--;
            arr[0][0] = 1;
        }

        emp_gift(); //일감 할당

        emp_work(); //포장
    }

    //output
    cout << answer;
}
