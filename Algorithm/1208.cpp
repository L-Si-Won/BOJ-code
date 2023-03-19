#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, s;
long long answer;
vector<int> seq;
unordered_map<int, int> sum_set;

void left_seq(int cur, int sum){
    if (cur == n / 2){
        sum_set[sum]++;
        return ;
    }

    left_seq(cur + 1, sum + seq[cur]);
    left_seq(cur + 1, sum);
}

void right_seq(int cur, int sum){
    if (cur == n){
        answer += sum_set[s - sum];
        return ;
    }

    right_seq(cur + 1, sum + seq[cur]);
    right_seq(cur + 1, sum);
}

void MITM(){
    left_seq(0, 0);
    right_seq(n / 2, 0);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }

    //meet in the middle
    MITM();

    //output
    if (s == 0)
        cout << answer - 1;
    else
        cout << answer;
}
