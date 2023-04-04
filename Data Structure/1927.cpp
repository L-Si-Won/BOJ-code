#include <iostream>
#include <queue>

using namespace std;

int n, x;
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    while(n--){
        cin >> x;

        if (x == 0){
            if (q.size() == 0)
                cout << "0\n";
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
            q.push(x);
    }
}
