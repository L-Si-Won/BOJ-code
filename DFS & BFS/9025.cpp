#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int t, n;
pair<int, int> home, store[100], rock; //열 행
bool visit[100]; //편의점 방문여부

void solve(){
    if(abs(home.first-rock.first)+abs(home.second-rock.second)<=1000){
        cout << "happy\n";
        return ;
    }

    queue<pair<int, int>> q;
    q.push(home);

    while(!q.empty()){
        pair<int, int> cur=q.front();
        q.pop();

        if(cur==home){
            for(int i=0; i<n; i++){
                if(visit[i]==false && (abs(cur.first-store[i].first)+abs(cur.second-store[i].second)<=1000)){
                    q.push(store[i]);
                    visit[i]=true;
                }
            }
        }
        else{
            if(abs(cur.first-rock.first)+abs(cur.second-rock.second)<=1000){
                cout << "happy\n";
                return ;
            }
            for(int i=0; i<n; i++){
                if(visit[i]==false && (abs(cur.first-store[i].first)+abs(cur.second-store[i].second)<=1000)){
                    q.push(store[i]);
                    visit[i]=true;
                }
            }
        }
    }
    cout << "sad\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        cin >> home.first >> home.second;
        for(int j=0; j<n; j++)
            cin >> store[j].first >> store[j].second;
        cin >> rock.first >> rock.second;
        solve();
        memset(visit, false, sizeof(visit));
    }
}
