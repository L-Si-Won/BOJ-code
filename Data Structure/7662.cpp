#include <iostream>
#include <set>

using namespace std;

int t, k;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> t;
    
    while(t--){
        cin >> k;

        //calculate
        multiset<int> set;

        for(int i = 0; i < k; i++){
            char c;
            int n;

            cin >> c >> n;

            if (c == 'D' && !set.empty()){
                if (n == 1)
                    set.erase(--set.end());
                else if (n == -1)
                    set.erase(set.begin());
            }
            else if (c == 'I')
                set.insert(n);
        }

        //output
        if (set.empty())
            cout << "EMPTY\n";
        else
            cout << *(--set.end()) << " " << *set.begin() << "\n";
    }
}
