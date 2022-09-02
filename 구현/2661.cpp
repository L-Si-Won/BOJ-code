#include <iostream>

using namespace std;

int n;
string s;

void solve(string s, int cnt){
    for(int i=1; i<=s.size()/2; i++)
        if(s.substr(s.size()-i, i)==s.substr(s.size()-i*2, i))
            return;
    
    if(cnt==n){
        cout << s;
        exit(0);
    }

    for(int i=0; i<n; i++){
        solve(s+"1", cnt+1);
        solve(s+"2", cnt+1);
        solve(s+"3", cnt+1);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    solve("", 0);
}
