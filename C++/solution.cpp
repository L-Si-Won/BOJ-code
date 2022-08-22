#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m, answer;
vector<long long> tree;

long long calculate(long long l){
    long long sum=0;
    for(int i=0; i<tree.size(); i++)
        if(tree[i]>=l) sum+=tree[i]-l;
    return sum;
}

void solve(){
    long long left=0, right=tree[tree.size()-1];
    long long mid, sum;
    while(left<=right){
        mid=(left+right)/2;
        sum=calculate(mid);

        if(sum>=m){
            answer=mid;
            left=mid+1;
        }
        else if(sum<m)
            right=mid-1;
    }
    
    cout << answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        tree.push_back(a);
    }

    sort(tree.begin(), tree.end());

    solve();
}