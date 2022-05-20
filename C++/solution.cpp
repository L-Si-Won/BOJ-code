#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[100001];
int ans[100001];
queue<int> q;
int n;
bool visit[100001];

void bfs(){
    visit[1]=true;
    q.push(1);
    int idx=2;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        int cnt=0;
        for(int i=0; i<v[cur].size(); i++){
            if(visit[v[cur][i]]==false){
                visit[v[cur][i]]=true;
                cnt++;
            }
        }

        for(int i=idx; i<idx+cnt; i++){
            if(visit[ans[i]]==false){
                cout << "0";
                exit(0);
            }
            q.push(ans[i]);
        }
        idx+=cnt;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<n+1; i++){
        cin >> ans[i];
    }
    if(ans[1]!=1){
        cout << "0";
        return 0;
    }
    bfs();
    cout << "1";
}