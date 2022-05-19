#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
queue<pair<int, int>> q;
bool visit[100001];
int cnt[100001];
int temp=2e9;

void bfs(int start){
    q.push({start, 0});
    while(!q.empty()){
        int cur=q.front().first;
        int cur_sec=q.front().second;
        if(cur==k){
            if(temp<cur_sec){
                cout << temp << "\n";
                cout << cnt[temp];
                exit(0);
            }
            temp=cur_sec;
            cnt[temp]++;
        }
        visit[cur]=true;
        q.pop();
        for(int i=0; i<3; i++){
            if(i==0){
                if(cur+1<=100000){
                    int next=cur+1;
                    int next_sec=cur_sec+1;
                    if(visit[next]==false){
                        q.push({next, next_sec});
                    }
                }
            }
            if(i==1){
                if(cur-1>=0){
                    int next=cur-1;
                    int next_sec=cur_sec+1;
                    if(visit[next]==false){
                        q.push({next, next_sec});
                    }
                }
            }
            if(i==2){
                if(cur*2<=100000){
                    int next=cur*2;
                    int next_sec=cur_sec+1;
                    if(visit[next]==false){
                        q.push({next, next_sec});
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
        cout << "0\n1";
        return 0;
    }
    bfs(n);
    cout << temp << "\n";
    cout << cnt[temp];
}