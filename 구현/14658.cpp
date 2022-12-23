#include <iostream>
#include <vector>

using namespace std;

int n, m, l, k, max_star;
vector<pair<int, int>> star;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> l >> k;
    for(int i=0; i<k; i++){
        int x, y;
        cin >> x >> y;
        star.push_back({x, y});
    }

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            int cur_x=star[i].first;
            int cur_y=star[j].second;
            int trampoline_star=0;

            for(int a=0; a<k; a++){
                //모든 범위를 확인
                int temp_x=star[a].first;
                int temp_y=star[a].second;

                if(temp_x>=cur_x && temp_x<=cur_x+l && temp_y>=cur_y && temp_y<=cur_y+l)
                    trampoline_star++;
            }

            max_star=max(max_star, trampoline_star);
        }
    }

    cout << k-max_star;
}
