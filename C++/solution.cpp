#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[9];

bool comp(int i, int j){
    return i > j;
}

bool dfs(){
    int i = n-1;
    while(i>0 && arr[i-1]>arr[i]) i--;
    if(i<=0) return false;

    int j=n-1;
    while(arr[i-1]>arr[j]) j--;
    swap(arr[i-1], arr[j]);
    sort(arr+i, arr+n);
    return true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++)
        arr[i]=i+1;
    
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    while(dfs()){
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
}