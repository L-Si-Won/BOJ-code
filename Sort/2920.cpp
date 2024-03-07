#include <iostream>

using namespace std;

int arr[8];
bool asc = 1, desc = 1;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 8; i++)
        cin >> arr[i];

    for (int i = 1; i < 8; i++)
        if (arr[i - 1] > arr[i])
            asc = false;

    for (int i = 1; i < 8; i++)
        if (arr[i - 1] < arr[i])
            desc = false;

    if (asc == true)
        cout << "ascending\n";
    else if (desc == true)
        cout << "descending\n";
    else
        cout << "mixed\n";
}
