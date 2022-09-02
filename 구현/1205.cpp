#include <iostream>
#include <algorithm>

using namespace std;

int n, p, score;
int arr[50];

bool comp(int a, int b){
    return a > b ? true : false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> score >> p;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    if(n>0) sort(arr, arr+n-1, comp);

    int answer=1;
    int same=0;
    for(int i=0; i<n; i++){
        if(arr[i]>score) answer++;
        else if(arr[i]==score) same++;
        else break;
    }
    if(answer+same>p) cout << -1;
    else cout << answer;
}
