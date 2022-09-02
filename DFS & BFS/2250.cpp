#include <iostream>
#include <queue>

using namespace std;

int n;
int root;
int col[10001];
int level[10001];
int order=1;
int real[10001];
pair<int, int> ans; //레벨, 너비

struct node{
    int par=0;
    int left;
    int right;
};
node arr[10001];

void LVR(int start, int l){
    if(start==-1) return;
    LVR(arr[start].left, l+1);
    col[order]=start;
    real[start]=order++;
    level[start]=l;
    LVR(arr[start].right, l+1);
}

void solve(){
    for(int i=1; i<=n; i++){ //레벨 검사
        int MAX=-1, MIN=2e9;
        for(int j=1; j<=n; j++){ //해당레벨끼리 검사
            if(level[j]==i){
                MAX=max(MAX, real[j]);
                MIN=min(MIN, real[j]);
            }
        }
        if(MAX==-1) return;
        if(ans.second < MAX-MIN+1){
            ans.first=i;
            ans.second=MAX-MIN+1;
        }
    }
}

void find_root(){
    for(int i=1; i<=n; i++){
        if(arr[i].par==0)
            root=i;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].left=b;
        arr[a].right=c;
        arr[b].par=a;
        arr[c].par=a;
    }
    find_root();
    LVR(root, 1);
    solve();
    cout << ans.first << " " << ans.second;
}
