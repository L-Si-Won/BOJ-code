#include <iostream>

using namespace std;

int T, a, b;

int GCD(int a, int b){
    int tmp, n;
 
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b != 0){
        n = a % b;
        a = b;
        b = n;
    }

    return a;
}


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> T;

    //test data
    while (T--){
        cin >> a >> b;

        int temp_a = a;
        int temp_b = b;
        int x = 1;

        //henry's algorithm
        while(1){

            //output
            if (temp_a == 1){
                cout << temp_b << "\n";
                break;
            }

            if (temp_b % temp_a == 0)
                x = temp_b / temp_a;
            else
                x = temp_b / temp_a + 1;

            temp_a = temp_a * x - temp_b;
            temp_b = temp_b * x;

            int gcd = GCD(temp_a, temp_b);
            temp_a /= gcd;
            temp_b /= gcd;
        }
    }
}
