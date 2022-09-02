#include <iostream>
#include <vector>

using namespace std;

#define INF 2100000000
int n, m;
vector<pair<int, int>> bus[501]; //(도착도시, 소모시간)
long long time[501]; //각 도시까지 걸리는 최소시간

void solve(){
    time[1]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<bus[j].size(); k++){
                int next=bus[j][k].first;
                int ncost=bus[j][k].second;

                if(time[j]!=INF && time[next]>time[j]+ncost){
                    time[next]=time[j]+ncost;
                    if(i==n){
                        cout << -1;
                        return;
                    }
                }
            }
        }
    }

    for(int i=2; i<=n; i++)
        if(time[i]==INF) cout << -1 << "\n";
        else cout << time[i] << "\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }
    for(int i=1; i<=n; i++) time[i]=INF;

    solve();
}
