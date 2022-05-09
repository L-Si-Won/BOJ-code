#include <iostream>

using namespace std;

int n;
string cmd;
int x;
int bit;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd=="all" || cmd=="empty"){
            if(cmd=="all")
                bit=(1<<21)-1;
            if(cmd=="empty")
                bit=0;
        }
        else{
            cin >> x;
            if(cmd=="add")
                bit=bit|(1<<x);
            if(cmd=="remove")
                bit=bit&~(1<<x);
            if(cmd=="check"){
                if(bit&(1<<x))
                    cout << "1\n";
                else   
                    cout << "0\n";
            }
            if(cmd=="toggle")
                bit=bit^(1<<x);
        }
    }
}