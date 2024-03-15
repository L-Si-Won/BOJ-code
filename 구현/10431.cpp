#include <iostream>

using namespace std;

int p, t, arr[20];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> p;

    while (p--){
        cin >> t;

        int walk = 0;
        for (int i = 0; i < 20; i++){

            //insert end
            cin >> arr[i];

            //search first taller
            for (int j = 0; j < i; j++){
                if (arr[i] < arr[j]){
                    //move counter
                    walk += i - j;

                    //back move
                    int temp = arr[i];
                    for (int k = i; k > j; k--)
                        arr[k] = arr[k - 1];
                    arr[j] = temp;
                }
            }
        }

        cout << t << " " << walk << "\n";
    }
}
