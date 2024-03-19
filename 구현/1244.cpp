#include <iostream>

using namespace std;

int sw, state[101], t, s, n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> sw;
    for (int i = 1; i <= sw; i++)
        cin >> state[i];
    cin >> t;

    while (t--){
        cin >> s >> n;

        //man
        if (s == 1){
            for (int i = 1; i <= sw; i++)
                if (i % n == 0)
                    state[i] = (state[i] == 1 ? 0 : 1);
        }
        //women
        else{
            state[n] = state[n] == 1 ? 0 : 1;
            for (int i = 1; ; i++){
                if (n + i > sw || n - i < 1)
                    break;

                if (state[n + i] == state[n - i]){
                    state[n + i] = (state[n + i] == 1 ? 0 : 1);
                    state[n - i] = (state[n - i] == 1 ? 0 : 1);
                }
                else
                    break;
            }
        }
    }

    for (int i = 1; i <= sw; i++){
        if (i > 20 && i % 20 == 1)
            cout << "\n";
        cout << state[i] << " ";
    }
}
