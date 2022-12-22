#include <iostream>
#include <algorithm>

using namespace std;

void fun(string s, string t){
    if(s.length()==t.length()){
        if(s.compare(t)==0){
            cout << 1;
            exit(0);
        }
        else return;
    }

    if(t[t.length()-1]=='A'){
        string temp=t;
        temp.erase(temp.end()-1);
        fun(s, temp);
    }
    if(t[0]=='B'){
        string temp=t;
        temp.erase(temp.begin());
        reverse(temp.begin(), temp.end());
        fun(s, temp);
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    fun(s, t);

    cout << 0;
}
