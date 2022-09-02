#include <iostream>
#include <string>

using namespace std;

int n;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    while(1){
        string s;
        s=to_string(n);
        bool palin=true;
        for(int i=0; i<s.size()/2; i++){
            char head=s.at(i);
            char tail=s.at(s.size()-1-i);
            if(head!=tail) palin=false;
        }
        if(palin==false){
            n++;
            continue;
        }
        bool prime=true;
        for(int i=2; i*i<=n; i++)
            if(n%i==0) prime=false;
        if(prime==false) n++;
        else{
            if(n==1){
                n++;
                continue;
            }
            cout << n;
            return 0;
        }
    }
}
