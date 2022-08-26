#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[301];
int d[301];

int dp(){
    d[1]=arr[1];
    d[2]=arr[1]+arr[2];
    d[3]=max(arr[1]+arr[3], arr[2]+arr[3]);

    for(int i=3; i<n+1; i++)
        d[i]=max(arr[i]+arr[i-1]+d[i-3], arr[i]+d[i-2]);
    return d[n];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<n+1; i++)
        cin >> arr[i];
    cout << dp();
}
