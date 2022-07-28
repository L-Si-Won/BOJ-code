#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> ch;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        ch.push_back(s);
    }

    int k1, k2;
    for(int i=0; i<n; i++)
        if(ch[i]=="KBS1") k1=i;
    for(int i=0; i<k1; i++) cout << 1;
    for(int i=0; i<k1; i++) cout << 4;

    for(int i=0; i<n; i++)
        if(ch[i]=="KBS2") k2=i;
    if(k1>k2) k2++;
    for(int i=0; i<k2; i++) cout << 1;
    for(int i=0; i<k2-1; i++) cout << 4;    
}