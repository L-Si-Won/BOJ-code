#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
double answer;
vector<pair<double, double>> point;


//외적구하기
double ccw(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3){
    pair<double, double> v={p2.first-p1.first, p2.second-p1.second};
    pair<double, double> u={p3.first-p1.first, p3.second-p1.second};
    double result=v.first*u.second-u.first*v.second;
    
    return result/2; //외적은 평행사변형의 넓이
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        double x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }

    for(int i=2; i<n; i++)
        answer+=ccw(point[0], point[i-1], point[i]);

    printf("%.1lf", abs(answer));
}
