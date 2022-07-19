#include <iostream>
#include <stack>

using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    int ans=0;
    int temp=1;
    stack<char> s;

    for(int i=0; i<str.length(); i++){
        if(str[i]=='('){
            temp*=2;
            s.push(str[i]);
        }
        else if(str[i]==')'){
            if(s.empty() || s.top()!='('){
                cout << 0;
                return 0;
            }
            if(str[i-1]=='(') ans+=temp;
            temp/=2;
            s.pop();
        }
        else if(str[i]=='['){
            temp*=3;
            s.push(str[i]);
        }
        else if(str[i]==']'){
            if(s.empty() || s.top()!='['){
                cout << 0;
                return 0;
            }
            if(str[i-1]=='[') ans+=temp;
            temp/=3;
            s.pop();
        }
    }
    if(!s.empty()) cout << 0;
    else cout << ans;
}