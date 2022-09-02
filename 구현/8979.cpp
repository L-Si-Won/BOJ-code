#include <iostream>
#include <vector>

using namespace std;

int n, k;
int gold[1001];
int silver[1001];
int bronze[1001];
int answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=1; i<=n; i++){
       int a, b, c, d;
       cin >> a >> b >> c >> d;
       gold[a]=b; silver[a]=c; bronze[a]=d;
    }
    for(int i=1; i<=n; i++){
        if(i==k) continue;
        if(gold[k]<gold[i]) answer++;
        else if(gold[k]==gold[i]){
            if(silver[k]<silver[i]) answer++;
            else if(silver[k]==silver[i]){
                if(bronze[k]<bronze[i]) answer++;
            }
        }
    }
    cout << answer+1;
}
