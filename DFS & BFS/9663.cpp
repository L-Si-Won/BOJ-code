#include <iostream>

using namespace std;

int n, answer;
int queen[15];

bool check(int cur){
    for(int i = 0; i < cur; i++){
        if (queen[cur] == queen[i]) //수평 확인
            return false;
        
        if (cur - i == abs(queen[cur] - queen[i])) //대각 확인
            return false;
    }

    return true;
}

void dfs(int cur){
    if (cur == n){
        answer++;
        return ;
    }

    for(int i = 0; i < n; i++){
        queen[cur] = i;

        if (check(cur) == true)
            dfs(cur + 1);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    //back tracking
    dfs(0);

    //output
    cout << answer;
}
