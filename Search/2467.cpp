#include <iostream>

using namespace std;

int n, val[100000];
int sol1, sol2, min_value = 2e9;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> val[i];
    
    //binary search
    int start = 0;
    int end = n - 1;
    while (start < end){
        int temp = val[start] + val[end];

        if (abs(temp) < min_value){
            sol1 = val[start];
            sol2 = val[end];
            min_value = abs(temp);
        }

        if (temp > 0)
            end--;
        else if (temp < 0)
            start++;
        else if (temp == 0)
            break;
    }

    //output
    cout << sol1 << " " << sol2;
}
