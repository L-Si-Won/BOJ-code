#include <iostream>

using namespace std;

int n, m, score;
pair<string, int> title[100000];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> title[i].first >> title[i].second;
    
    for (int i = 0; i < m; i++){
        cin >> score;

        int l = 0;
        int r = n - 1;
        while (l < r){
            int mid = (l + r) / 2;

            if (score <= title[mid].second)
                r = mid;
            else if (score > title[mid].second)
                l = mid + 1;
        }

        cout << title[l].first << "\n";
    }

}
