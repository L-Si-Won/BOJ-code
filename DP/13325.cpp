#include <iostream>
#include <cmath>

using namespace std;

int k, tree[2'100'000 * 2];

int DP(int node, int max_node){

    if (node >= max_node)
        return 0;

    int left_sum = DP(node * 2, max_node) + tree[node * 2];
    int right_sum = DP(node * 2 + 1, max_node) + tree[node * 2 + 1];

    if (left_sum > right_sum)
        tree[node * 2 + 1] += left_sum - right_sum;
    else
        tree[node * 2] += right_sum - left_sum;
    
    return max(left_sum, right_sum);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> k;

    for (int i = 2; i < pow(2, k + 1); i++)
        cin >> tree[i];
    
    //dp
    DP(1, (int)pow(2, k + 1));

    //sum edges
    int sum = 0;
    for (int i = 2; i < pow(2, k + 1); i++)
        sum += tree[i];
    
    //output
    cout << sum;
}
