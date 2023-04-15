#include <iostream>

using namespace std;

int t, m, n, arr[100][100], answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> t;
    
    while(t--){
        cin >> m >> n;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        
        //아래서부터 박스내리기
        answer = 0;
        for(int i = m - 2; i >= 0; i--){ //맨아래는 확인할 필요x
            for(int j = n - 1; j >= 0; j--){
                if (arr[i][j] == 1){
                    int move_cnt = 1;

                    //내릴 수 있을 때까지 내리기
                    while (arr[i + move_cnt][j] == 0 && i + move_cnt < m)
                        move_cnt++;
                    move_cnt--;

                    if (move_cnt != 0){
                        arr[i][j] = 0;
                        arr[i + move_cnt][j] = 1;
                        answer += move_cnt;
                    }
                }
            }
        }

        //output
        cout << answer << "\n";
    }
}
