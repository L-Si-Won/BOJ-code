#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer;
vector<int> a;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n; i++){
        int num=a[i];
        int start=0, end=a.size()-1;
        while(start<end){
            int sum=a[start]+a[end];
            
            if(num==sum){
                if(start!=i && end!=i){
                    answer++;
                    break;
                }
                else if(start==i) start++;
                else if(end==i) end--;
            }
            else if(num<sum) end--;
            else if(num>sum) start++;
        }
    }

    cout << answer;
}
