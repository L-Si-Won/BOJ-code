#include <iostream>

using namespace std;

int T, H, W, N;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> T;

    //test data
    while (T--){
        cin >> H >> W >> N;

        int Y, X;

        //calculate floor
        Y = N % H;
        if (Y == 0)
            Y = H;

        //calculate distance from elevator
        X = N / H;
        if (N % H != 0)
            X++;

        //output
        cout << Y;
        if (X < 10)
            cout << "0";
        cout << X << "\n";
    }
}
