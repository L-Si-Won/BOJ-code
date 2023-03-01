#include <iostream>

using namespace std;

int n, m, arr[100000];
int min_value, max_value;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        min_value = max(min_value, arr[i]);
        max_value += arr[i];
    }

    //binary search
    while (min_value <= max_value){
        int blu_ray_cnt = 1;
        int blu_ray_size = 0;
        int mid_value = (min_value + max_value) / 2;

        for(int i = 0; i < n; i++){
            if (blu_ray_size + arr[i] <= mid_value)
                blu_ray_size += arr[i];
            else{
                blu_ray_size = arr[i];
                blu_ray_cnt++;
            }
        }

        if (blu_ray_cnt <= m)
            max_value = mid_value - 1;
        else
            min_value = mid_value + 1;
    }

    //output
    cout << min_value;
}
