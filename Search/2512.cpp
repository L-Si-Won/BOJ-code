#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[10000], m;
int answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> m;

    //sort
    sort(arr, arr + n);
    
    //binary search
    int low = 1;
    int high = arr[n - 1];

    while (low <= high){
        int mid = (low + high) / 2;
        int temp = m;
        bool flag = true;

        for (int i = 0; i < n; i++){

            //lack of money
            if (temp < arr[i] && temp < mid){
                flag = false;
                break;
            }

            //budget allocation
            if (arr[i] > mid)
                temp -= mid;
            else
                temp -= arr[i];
        }

        if (flag == true){
            answer = max(answer, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    //output
    cout << answer;
}
