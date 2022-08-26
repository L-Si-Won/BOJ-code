#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[15];
int p[15];
int d[15][2];
int MAX;

int dp(){
    if(t[0]<=n) d[0][1]=p[0];

    for(int i=1; i<n; i++){
        d[i][0]=max(d[i-1][0], d[i-1][1]);
        
        if(i+t[i]<=n){
            d[i][1]=p[i];
            for(int j=i-1; j>=0; j--){
                if(i-j>=t[j])
                    d[i][1]=max(d[i][1], d[j][1]+p[i]);
            }
        }
    }
    MAX=max(d[n-1][0], d[n-1][1]);
    return MAX;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> t[i] >> p[i];

    cout << dp();
}
