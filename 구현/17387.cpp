#include <iostream>

using namespace std;

struct line{
    pair<int, int> p1;
    pair<int, int> p2;
};

line l1, l2;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c){
    pair<int, int> v = {b.first - a.first, b.second - a.second};
    pair<int, int> u = {c.first - a.first, c.second - a.second};

    long long result = (long long)v.first * u.second - (long long)u.first * v.second;

    if (result > 0)
        return 1;
    else if (result == 0)
        return 0;
    else
        return -1;
}

bool cross_check(){
    //각 선분에 대한 방향
    int check_l1 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    int check_l2 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);

    //두 선분이 일직선 상에 존재하는 경우
    if (check_l1 == 0 && check_l2 == 0){
        //좌하단에 있는 점을 첫번째점으로 변경
        if (l1.p1 > l1.p2)
            swap(l1.p1, l1.p2);
        if (l2.p1 > l2.p2)
            swap(l2.p1, l2.p2);

        //두 선분이 겹쳐지는 경우
        if (l1.p1 <= l2.p2 && l1.p2 >= l2.p1)
            return true;
        else
            return false;
    }

    //두 선분이 한 점에서 만나는 경우
    if (check_l1 <= 0 && check_l2 <= 0)
        return true;
    //교차하지 않는 경우
    else
        return false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> l1.p1.first >> l1.p1.second >> l1.p2.first >> l1.p2.second;
    cin >> l2.p1.first >> l2.p1.second >> l2.p2.first >> l2.p2.second;

    //check and output
    if (cross_check() == true)
        cout << 1;
    else
        cout << 0;
}
