#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a, seq;

void binary_search(int cur){
    int start = 0;
    int end = seq.size() - 1;
    int update_idx = 2e9;

    while (start <= end){
        int mid = (start + end) / 2;

        if (seq[mid] >= a[cur]){
            update_idx = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }

    seq[update_idx] = a[cur];
}

void LIS(){
    seq.push_back(a[0]);

    for(int i = 1; i < n; i++){
        if (a[i] > seq.back())
            seq.push_back(a[i]);
        else
            binary_search(i);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    //find LIS
    LIS();

    //output
    cout << seq.size();
}
