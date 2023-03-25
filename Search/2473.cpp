#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[5000];
long long sum = 3000000000;
int sol1, sol2, sol3;

void binary_search(){

    for(int fix = 0; fix < n - 2; fix++){
        int start = fix + 1;
        int end = n - 1;

        while (start < end){
            long long temp_sum = (long long)arr[fix] + arr[start] + arr[end];

            if (abs(temp_sum) < abs(sum)){
                sol1 = arr[fix];
                sol2 = arr[start];
                sol3 = arr[end];

                sum = temp_sum;
            }

            if (temp_sum >= 0)
                end--;
            else
                start++;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    //sort
    sort(arr, arr + n);

    //binary search
    binary_search();

    //output
    cout << sol1 << " " << sol2 << " " << sol3;
}
