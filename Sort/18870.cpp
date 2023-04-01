#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> x, temp, answer;

int binary_search(int num){
    int start = 0;
    int end = temp.size() - 1;

    while(start <= end){
        int mid = (start + end) / 2;

        if (temp[mid] == num)
            return mid;
        else if(temp[mid] < num)
            start = mid + 1;
        else if(temp[mid] > num)
            end = mid - 1;
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        x.push_back(a);
    }

    //sort
    temp = x;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    //binary_search and output
    for(int i = 0; i < n; i++)
        cout << binary_search(x[i]) << " ";
}
