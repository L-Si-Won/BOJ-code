#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n, k;
queue<pair<int, int>> q;
bool visit[100001];
int cnt[100001];
int parent[100001];
stack<int> s;

void bfs(int start){
    visit[start]=true;
    q.push({start, 0});
    while(!q.empty()){
        int cur=q.front().first;
        int cur_sec=q.front().second;
        if(cur==k){
            int path=cur;
            while(path!=n){
                s.push(path);
                path=parent[path];
            }
            s.push(path);
            cout << cur_sec << "\n";
            break;
        }
        q.pop();
        for(int i=0; i<3; i++){
            if(i==0){
                if(cur+1<=100000){
                    int next=cur+1;
                    int next_sec=cur_sec+1;
                    if(visit[next]==false){
                        visit[next]=true;
                        q.push({next, next_sec});
                        parent[next]=cur;
                    }
                }
            }
            if(i==1){
                if(cur-1>=0){
                    int next=cur-1;
                    int next_sec=cur_sec+1;
                    if(visit[next]==false){
                        visit[next]=true;
                        q.push({next, next_sec});
                        parent[next]=cur;
                    }
                }
            }
            if(i==2){
                if(cur*2<=100000){
                    int next=cur*2;
                    int next_sec=cur_sec+1;
                    if(visit[next]==false){
                        visit[next]=true;
                        q.push({next, next_sec});
                        parent[next]=cur;
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

    cin >> n >> k;
    if(n==k){
        cout << "0\n" << n;
        return 0;
    }
    bfs(n);
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
