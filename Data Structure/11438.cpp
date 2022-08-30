#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v[100001]; //간선 정보
int parent[100001][17]; //정점의 부모 정보
int level[100001]; //정점의 레벨

void init_tree(int node, int pnode, int lv){
    level[node]=lv;
    parent[node][0]=pnode;

    //log2(100000)>16 이므로 최대 레벨은 16이하
    for(int i=1; i<=16; i++)
        //node의 2^i번째 조상는 node의 2^(i-1)번째 조상의 2^(i-1)번째 조상
        parent[node][i]=parent[parent[node][i-1]][i-1];
    
    for(int i=0; i<v[node].size(); i++)
        if(v[node][i]!=pnode) //node와 연결된 정점이 부모가 아닐 경우
            init_tree(v[node][i], node, lv+1);
}

int LCA(int a, int b){
    //둘 중 하나라도 1이면 공통 조상은 1
    if(a==1 || b==1) return 1;

    int low=a, high=b;
    //더 레벨이 낮은 놈 찾기
    if(level[a]<level[b]) swap(high, low);

    //low와 high의 레벨이 같게 만들기
    if(level[low]!=level[high])
        for(int i=16; i>=0; i--) //최대 레벨은 16
            if(level[parent[low][i]]>=level[high])
                low=parent[low][i];
    
    //위에서부터 내려오며 공통 조상 찾기
    int temp=low;
    if(low!=high){
        for(int i=16; i>=0; i--){
            if(parent[low][i]!=parent[high][i]){
                low=parent[low][i];
                high=parent[high][i];
            }
            temp=parent[low][i];
        }
    }

    return temp;
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

    init_tree(1, 0, 1);

    cin >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}
