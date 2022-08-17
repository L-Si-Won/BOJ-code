#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int t, n;
vector<string> v; //10자리 or 0으로 시작

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while(t--){
        cin >> n;
        v.clear();
        string temp;
        for(int i=0; i<n; i++){
            cin >> temp;
            v.push_back(temp);
        }
        
        sort(v.begin(), v.end());
        
        bool flag=true;
        for(int i=0; i<v.size()-1; i++){
            if(v[i].length()<=v[i+1].length()){
                if(v[i]==v[i+1].substr(0, v[i].size())){
                    flag=false;
                    break;
                }
            }
        }

        if(flag==false) cout  << "NO\n";
        else cout << "YES\n";
    }
}