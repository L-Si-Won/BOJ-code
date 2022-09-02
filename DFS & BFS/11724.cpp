#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
vector<int> arr[1001];
bool visit[1001];
int cnt;

void dfs(int cur){
    visit[cur]=true;
    //cout << cur << " ";
    for(int i=0; i<arr[cur].size(); i++){
        int next=arr[cur][i];
        if(visit[next]==false) dfs(next);
    }
}

void bfs(int cur){
    queue<int> q;
    q.push(cur);
    visit[cur]=true;
    while(!q.empty()){
        int c=q.front();
        q.pop();
        cout << c << " ";
        for(int i=0; i<arr[c].size(); i++){
            int next=arr[c][i];
            if(visit[next]==false){
                visit[next]=true;
                q.push(next);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<m+1; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1; i<n+1; i++){
        if(visit[i]==false){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}
