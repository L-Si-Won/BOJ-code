#include <iostream>
#define ll long long

using namespace std;

int n, A[500'000], B[1'000'001];
ll tree[2'000'000], answer;

//주어진 구간의 합 구하기
ll sum(int cur, int start, int end, int sum_start, int sum_end){
    if (!(sum_start <= end && sum_end >= start))
        return 0;

    if (sum_start <= start && end <= sum_end)
        return tree[cur];

    int mid = (start + end) / 2;

    return sum(cur * 2, start, mid, sum_start, sum_end) +
            sum(cur * 2 + 1, mid + 1, end, sum_start, sum_end);
}


//방문한 노드 방문 처리하고, 트리 전체 갱신
void update(int cur, int start, int end, int visit_idx){

    if (!(visit_idx >= start && visit_idx <= end))
        return;
    
    if (start == end){
        tree[cur] = 1;
        return;
    }

    int mid = (start + end) / 2;

    update(cur * 2, start, mid, visit_idx);
    update(cur * 2 + 1, mid + 1, end, visit_idx);

    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        B[temp] = i;
    }

    //make segment tree
    for(int i = 0; i < n; i++){
        answer += sum(1, 0, n - 1, B[A[i]] + 1, n - 1);
        update(1, 0, n - 1, B[A[i]]);
    }

    //output
    cout << answer;
}
