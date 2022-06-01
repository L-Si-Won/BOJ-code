#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d;
bool visit[1000001];
int dp[1000001];

void solve(){
    queue<int> q;
    q.push(s);
    visit[s]=true;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        if(cur==g){
            cout << dp[g];
            exit(0);
        }

        for(int i=0; i<2; i++){
            if(i==0){
                int next=cur+u;
                if(next<=f){
                    if(visit[next]==false || dp[next]>dp[cur]+1){
                        visit[next]=true;
                        dp[next]=dp[cur]+1;
                        q.push(next);
                    }
                }
            }
            if(i==1){
                int next=cur-d;
                if(next>=1){
                    if(visit[next]==false || dp[next]>dp[cur]+1){
                        visit[next]=true;
                        dp[next]=dp[cur]+1;
                        q.push(next);
                    }
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> f >> s >> g >> u >> d;
    solve();
    cout << "use the stairs";
}