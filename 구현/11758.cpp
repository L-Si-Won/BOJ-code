#include <iostream>

using namespace std;

int x1, x2, x3, y1, y2, y3;
pair<int, int> v; //p1과 p2를 이은 벡터
pair<int, int> u; //p1과 p3를 이은 벡터
int result; //v*u 결과값

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    v={x2-x1, y2-y1};
    u={x3-x1, y3-y1};

    //외적
    result=v.first*u.second-u.first*v.second;
    if(result<0) cout << -1;
    else if(result==0) cout << 0;
    else cout << 1;
}
