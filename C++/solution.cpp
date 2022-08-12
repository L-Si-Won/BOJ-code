#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
pair<int, int> grd[100000]; //서류, 면접

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first ? true : false;
}

void solve(){
    sort(grd, grd+n, comp);
    pair<int, int> temp=grd[0];
    int answer=1;

    for(int i=1; i<n; i++){
        if(temp.second > grd[i].second){
            answer++;
            temp=grd[i];
        }
    }
    cout << answer << "\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        for(int i=0; i<100000; i++){
            grd[i]={0, 0};
        }

        cin >> n;
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            grd[i]={a, b};
        }
        solve();
    }
}