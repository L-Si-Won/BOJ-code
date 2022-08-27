#include <iostream>

using namespace std;

int n, m;
int parent[1000001];

int getParent(int a){ //부모 찾기
    if(parent[a]==a) return a;
    return parent[a]=getParent(parent[a]);
}

void unionParent(int a, int b){ //부모 정하기
    a=getParent(a);
    b=getParent(b);
    
    if(a>b) parent[a]=b;
    else parent[b]=a;
}

void findParent(int a, int b){ //부모 비교하기
    a=getParent(a);
    b=getParent(b);

    if(a==b) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<=n; i++)
        parent[i]=i;

    while(m--){
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if(cmd==0){
            unionParent(a, b);
        }
        else if(cmd==1){
            findParent(a, b);
        }
    }
}
