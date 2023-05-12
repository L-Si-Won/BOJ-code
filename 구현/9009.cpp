#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, fibo[46];

void fibonacci(){
    fibo[1] = 1;

    //fibonacci(45) = 1134903170 으로, n을 커버할 수 있음
    for(int i = 2; i < 46; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //fibonacci
    fibonacci();

    //input
    cin >> t;
    while (t--){
        cin >> n;

        vector<int> answer;

        for(int i = 45; i >= 0; i--){
            if (fibo[i] <= n){
                n -= fibo[i];
                answer.push_back(fibo[i]);
            }

            if (n == 0)
                break;
        }

        //오름차순으로 정렬
        sort(answer.begin(), answer.end());

        //output
        for(int i = 0; i < answer.size(); i++)
            cout << answer[i] << " ";
        cout << "\n";
    }
}
