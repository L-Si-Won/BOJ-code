#include <iostream>

using namespace std;

int n, parent[3001], group_size[3001], max_size, group_cnt;
pair<pair<double, double>, pair<double, double>> line[3001];

//부모 찾기
int getParent(int a){
    if(parent[a]==a) return a;
    return parent[a]=getParent(parent[a]);
}

//부모 정하기
void unionParent(int a, int b){
    a=getParent(a);
    b=getParent(b);

    if(a>b) parent[a]=b;
    else parent[b]=a;
}

//외적 구하기
double ccw(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    pair<double, double> v={p2.first-p1.first, p2.second-p1.second};
    pair<double, double> u={p3.first-p1.first, p3.second-p1.second};
    double result=v.first*u.second-u.first*v.second;

    return result;
}

//선분이 서로 만나는지 체크
bool cross_check(pair<pair<double, double>, pair<double, double>> l1, 
    pair<pair<double, double>, pair<double, double>>l2){
    
    double ccw1=ccw(l1.first, l1.second, l2.first)*ccw(l1.first, l1.second, l2.second);
    double ccw2=ccw(l2.first, l2.second, l1.first)*ccw(l2.first, l2.second, l1.second);
    
    if(ccw1<=0 && ccw2<=0){
        if((l1.first.first<l2.first.first && l1.first.first<l2.second.first && l1.second.first<l2.first.first && l1.second.first<l2.second.first) ||
            (l2.first.first<l1.first.first && l2.first.first<l1.second.first && l2.second.first<l1.first.first && l2.second.first<l1.second.first))
            return false;
        if((l1.first.second<l2.first.second && l1.first.second<l2.second.second && l1.second.second<l2.first.second && l1.second.second<l2.second.second) ||
            (l2.first.second<l1.first.second && l2.first.second<l1.second.second && l2.second.second<l1.first.second && l2.second.second<l1.second.second))
            return false;
        return true;
    }

    return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<=n; i++){
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line[i]={{x1,y1}, {x2,y2}};
        parent[i]=i; //최초의 부모는 자기 자신
    }

    //그룹화하기
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(cross_check(line[i], line[j]))
                unionParent(i, j);

    //그룹별 크기 구하기
    for(int i=1; i<=n; i++)
        group_size[getParent(i)]++;

    //최대 그룹 크기와 그룹 개수 구하기
    for(int i=1; i<=n; i++){
        max_size=max(max_size, group_size[i]);
        if(group_size[i]>0) group_cnt++;
    }

    cout << group_cnt << "\n" << max_size;
}
