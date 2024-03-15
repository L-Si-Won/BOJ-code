#include <iostream>

using namespace std;

int n;
pair<int, int> arr[50];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;

    for (int i = 0; i < n; i++){
        int k = 0;

        for (int j = 0; j < n; j++)
            if (i != j && arr[i].first <arr[j].first && arr[i].second < arr[j].second)
                k++;
        
        cout << k + 1 << " ";
    }
}
