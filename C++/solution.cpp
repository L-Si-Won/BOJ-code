#include <iostream>

using namespace std;

int n, m, answer;
int arr[10001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int start=0, end=0, sum=0;
    while(start<=end && end<=n){
        if(sum==m) answer++;

        if(sum<=m){
            end++;
            if(end<=n) sum+=arr[end];
        }
        else if(sum>m){
            sum-=arr[start];
            start++;
            if(start>end){
                end++;
                if(end<=n) sum+=arr[end];
            }
        }
    }

    cout << answer;
}