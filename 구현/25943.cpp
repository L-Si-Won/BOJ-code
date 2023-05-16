#include <iostream>

using namespace std;

int n, w[10000], scale[2];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> w[i];

        //put on scale
        if (i == 0)
            scale[0] += w[i];
        else if (i == 1)
            scale[1] += w[i];
        else{
            if (scale[0] <= scale[1])
                scale[0] += w[i];
            else
                scale[1] += w[i];
        }
    }

    int add_w = 0;
    while (scale[0] != scale[1]){
        if (scale[0] < scale[1]){
            scale[0]++;
            add_w++;
        }
        else{
            scale[1]++;
            add_w++;
        }
    }

    int answer = 0;
    int temp[7] = {1, 2, 5, 10, 20, 50, 100};
    for (int i = 6; i >= 0; i--){
        while (add_w / temp[i] != 0){
            answer += add_w / temp[i];
            add_w = add_w % temp[i];
        }
    }

    cout << answer;
}
