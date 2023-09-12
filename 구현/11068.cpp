#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> v;

void dec_to_B(int n, int B){

    while (1){
        
        if (n / B == 0){
            v.push_back(n);
            break;
        }
        
        v.push_back(n % B);
        n /= B;
    }
}

bool Is_palin(){

    for (int i = 0; i < v.size() / 2; i++){

        if (v[i] != v[v.size() - i - 1])
            return false;
    }

    return true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> T;

    while (T--){
        int n;
        bool flag = false;

        cin >> n;

        //check palindrom
        for (int B = 2; B <= 64; B++){

            //init
            v.clear();

            dec_to_B(n, B);

            if (Is_palin() == true){
                flag = true;
                break;
            }
        }

        //output
        if (flag == true)
            cout << "1\n";
        else
            cout << "0\n";
    }
}
