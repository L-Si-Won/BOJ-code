#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr(3);

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (1){
        for (int i = 0; i < 3; i++)
            cin >> arr[i];

        if (arr[0] + arr[1] + arr[2] == 0)
            break;

        sort(arr.begin(), arr.end());

        if (arr[0] + arr[1] <= arr[2]){
            cout << "Invalid\n";
            continue;
        }

        int same = 0;

        for (int i = 0; i < 3; i++)
            for (int j = i + 1; j < 3; j++)
                if (arr[i] == arr[j])
                    same++;
        
        if (same == 3)
            cout << "Equilateral\n";
        else if (same == 1)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
}
