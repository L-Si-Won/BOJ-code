#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
pair<int, int> car[1000]; //{weight, position}

int t = 0;
bool out[1000];
int cur_w = 0;
int cur_car = 0;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> L >> w;

    for (int i = 0; i < n; i++)
        cin >> car[i].first;

    //simulation
    while (1){
        
        t++;

        //move truck on bridge
        for (int i = 0; i < cur_car; i++)
            car[i].second++;

        //check to get out bridge
        for (int i = 0; i < cur_car; i++){
            if (out[i] == false && car[i].second > L){
                cur_w -= car[i].first;
                out[i] = true;

                //cross all truck
                if (i == n - 1){
                    cout << t;
                    return 0;
                }
            }
        }
        
        //car go bridge
        if (cur_w < w){

            if (cur_w + car[cur_car].first <= w){
                car[cur_car].second++;
                cur_w += car[cur_car].first;
                cur_car++;
            }
        }
    }
}
