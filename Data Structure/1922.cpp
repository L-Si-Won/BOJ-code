#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class edge; //전방 선언
int n, m, sum;
vector<edge> v; //간선 정보
int parent[1001]; //부모

class edge{
public:
    int node[2];
    int dis;
    edge(int a, int b, int c){ //생성자
        this->node[0]=a;
        this->node[1]=b;
        this->dis=c;
    }

    bool operator<(edge &e){ //비교 연산자 오버로딩
        return this->dis < e.dis;
    }
};

int getParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=getParent(parent[x]);
}

void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);

    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int find(int a, int b){
    a=getParent(a);
    b=getParent(b);

    if(a==b) return 1;
    else return 0;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(edge(a, b, c));
    }

    //비용 기준으로 정렬
    sort(v.begin(), v.end()); 

    //초기엔 자기 자신이 부모
    for(int i=1; i<=n; i++) parent[i]=i; 

    //크루스칼 알고리즘
    for(int i=0; i<v.size(); i++){
        if(find(v[i].node[0], v[i].node[1])==0){ //서로 부모가 다를 때
            sum+=v[i].dis;
            unionParent(v[i].node[0], v[i].node[1]);
        }
    }

    cout << sum;
}
