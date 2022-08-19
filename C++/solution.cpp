#include <iostream>
#include <algorithm>

using namespace std;

int n, l, answer;
bool holl[1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> l;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        holl[a]=true;
    }
    
    for(int i=0; i<=1000; i++){
        if(holl[i]==true){
            for(int j=0; j<l; j++){
                if(i+j<=1000 && holl[i+j]==true) holl[i+j]=false;
            }
            answer++;
        }
    }

    cout << answer;
}