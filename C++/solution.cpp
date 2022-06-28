#include <iostream>
#include <queue>

using namespace std;

int n, arr[100001];

void solve(){
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    for(int i=1; i<=n; i++){
        if(max.size()==min.size()) max.push(arr[i]);
        else min.push(arr[i]);

        if(!max.empty() && !min.empty() && max.top()>min.top()){
            int val1, val2;
            val1=max.top();
            val2=min.top();
            max.pop();
            min.pop();
            max.push(val2);
            min.push(val1);
        }
        cout << max.top() << "\n";
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    solve();
}