#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, d, k, c, answer;
vector<int> dish;
bool eat[3001];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> d >> k >>c;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        dish.push_back(temp);
    }

    for(int i=0; i<n; i++){
        int same=0; //같은 종류의 초밥 수
        int coupon=1; //연속된 초밥에 쿠폰 초밥이 있는지

        for(int j=i; j<i+k; j++){
            int cur_dish=dish[j%n];

            if(eat[cur_dish]==true) same++;
            else eat[cur_dish]=true;

            if(cur_dish==c) coupon=0;
        }

        answer=max(answer, k-same+coupon);
        memset(eat, false, sizeof(eat));
    }

    cout << answer;
}
