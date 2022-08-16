#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int x;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (cin >> x){
        x*=10000000; //나노변환
        int n;
        cin >> n;
        /*
        if(n<2){
            cout << "danger\n";
            continue;
        }
        */
        v.clear();
        for(int i=0;i<n;i++){
            int temp;
            cin>> temp;
            v.push_back(temp);   
        }
        sort(v.begin(),v.end());

        int l=0,r=n-1,sum;
        bool flag=false;
        while(l<r){ //이분탐색
            sum = v[l]+v[r];
            if(sum==x){
                flag = true;
                cout << "yes " << v[l] << " " << v[r] << '\n';
                break;
            }
            else if(sum < x)  l++;
            else r--;
        }
        if(flag==false) cout << "danger\n";
    }
    return 0;
}