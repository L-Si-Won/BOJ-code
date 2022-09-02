#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[9];

int sum(){
    int sum=0;
    for(int i=0; i<n-1; i++)
        sum += abs(arr[i]-arr[i+1]);
    return sum;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int MAX=sum();
    while(next_permutation(arr, arr+n))
        MAX=max(MAX, sum());
    cout << MAX;
}
