#include <iostream>
#include <algorithm>

using namespace std;

struct team{
    int match = 0;
    int S = 0;
    int A = 0;
};

int T, n, m;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> T;

    while (T--){
        cin >> n >> m;

        team t[1001];

        for (int i = 0; i < m; i++){

            int a, b, p, q;

            cin >> a >> b >> p >> q;

            t[a].match++;
            t[a].S += p;
            t[a].A += q;

            t[b].match++;
            t[b].S += q;
            t[b].A += p;
        }

        float MAX, MIN;

        if (t[1].S * t[1].S + t[1].A * t[1].A == 0){
            MAX = 0;
            MIN = 0;
        }
        else{
            MAX = ((float)t[1].S * t[1].S) / ((float)t[1].S * t[1].S + t[1].A * t[1].A);
            MIN = ((float)t[1].S * t[1].S) / ((float)t[1].S * t[1].S + t[1].A * t[1].A);
        }

        for (int i = 2; i <= n; i++){
            if (t[i].S * t[i].S + t[i].A * t[i].A == 0){
                MAX = max(MAX, (float)0);
                MIN = min(MIN, (float)0);
            }
            else{
                MAX = max(MAX, ((float)t[i].S * t[i].S) / ((float)t[i].S * t[i].S + t[i].A * t[i].A));
                MIN = min(MIN, ((float)t[i].S * t[i].S) / ((float)t[i].S * t[i].S + t[i].A * t[i].A));
            }
        }

        //output
        cout << (int)(MAX * 1000) << "\n";
        cout << (int)(MIN * 1000) << "\n";
    }
}
