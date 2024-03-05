#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int k;
string s;
string arr[101010];
 
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> s >> k;
 
    //devide string
    for (int i = 0; i < s.length(); i++){
 
        arr[i % k] += s[i];
    }
 
    //sort
    for (int i = 0; i < k; i++)
        sort(arr[i].begin(), arr[i].end());
    
    //merge string
    int str_idx = 0, char_idx = 0;
    string answer = "";
    while (1){
 
        if (arr[str_idx].length() <= char_idx)
            break;
        
        answer += arr[str_idx][char_idx];
 
        str_idx++;
        if (str_idx >= k){
            char_idx++;
            str_idx = 0;
        }
    }
 
    cout << answer;
}
