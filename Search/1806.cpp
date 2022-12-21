#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s, answer=2e9;
vector<int> v;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int start=0, end=0;
    int sum=v[0];
    while(start<=end && end<n){
        if(sum>=s){
            answer=min(answer, end-start+1);
            sum-=v[start];
            start++;
        }
        else{
            end++;
            sum+=v[end];
        }
    }

    //답 출력
    if(answer==2e9) cout << 0;
    else cout << answer;
}
