#include <iostream>

using namespace std;

int n, seq[11];
char arr[11][11];

bool check_sign(int idx){
    bool flag = true;

    for(int k = 1; k <= idx; k++){
        int sum = 0;
        for(int j = k; j <= idx; j++)
            sum += seq[j];

        if (arr[k][idx] == '+')
            if (!(sum > 0))
                flag = false;
        if (arr[k][idx] == '-')
            if (!(sum < 0))
                flag = false;
        if (arr[k][idx] == '0')
            if (!(sum == 0))
                flag = false;
    }

    return flag;
}

void sol(int idx){
    if (idx == n + 1){ //output
        for(int i = 1; i <= n; i++)
            cout << seq[i] << " ";
        exit(0);
    }

    for(int i = -10; i <= 10; i++){
        seq[idx] = i;

        if (check_sign(idx) == true)
            sol(idx + 1);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    string s;
    cin >> s;
    int idx = 0;
    for(int i = n; i > 0; i--){
        for(int j = n - i + 1; j <= n; j++){
            arr[n - i + 1][j] = s[idx];
            idx++;
        }
    }

    //back tracking
    sol(1);
}
