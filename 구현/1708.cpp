#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n;
pair<long long, long long> point[100000];
stack<pair<long long, long long>> vertex;

//외적구하기
long long ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3){
    pair<long long, long long> v={p2.first-p1.first, p2.second-p1.second};
    pair<long long, long long> u={p3.first-p1.first, p3.second-p1.second};
    long long result=v.first*u.second-u.first*v.second;

    return result;
}

//더 반시계방향쪽에 있는 점 순으로 정렬
bool cmp(pair<long long, long long> p1, pair<long long, long long> p2){
    long long result=ccw(point[0], p1, p2);

    //일직선상에 존재하지 않으면
    //반시계방향에 더 치우쳐있는 점을 선택
    if(result) return result>0;

    //일직선상에 존재하면
    //더 하단에 있는 점을 선택
    else if(p1.second!=p2.second) return p1.second<p2.second;

    //같은 높이에 있으면
    //더 좌측에 있는 점을 선택
    else return p1.first<p2.first;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        long long x, y;
        cin >> x >> y;
        point[i]={x, y};
    }

    //가장 좌하단에 있는 점 선택
    for(int i=1; i<n; i++)
        if(point[i].second<point[0].second ||
            (point[i].second==point[0].second && point[i].first<point[0].first))          
            swap(point[0], point[i]);

    //좌하단점을 기준으로 다른 점들을 반시계방향으로 정렬
    sort(point+1, point+n, cmp);

    //꼭짓점 개수 구하기
    vertex.push(point[0]);
    vertex.push(point[1]);
    for(int i=2; i<n; i++){
        while(vertex.size()>=2){
            pair<long long, long long> temp1, temp2;
            temp1=vertex.top();
            vertex.pop();
            temp2=vertex.top();
            if(ccw(temp2, temp1, point[i])>0){
                vertex.push(temp1);
                break;
            }
        }
        vertex.push(point[i]);
    }

    cout << vertex.size();
}
