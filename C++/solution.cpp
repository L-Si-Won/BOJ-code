#include <iostream>

using namespace std;

int n;

struct node{
    char left;
    char right;
};
node arr[27];

void pre(char c){
    if(c=='.') return;
    cout << c;
    pre(arr[c-'A'].left);
    pre(arr[c-'A'].right);
}

void in(char c){
    if(c=='.') return;
    in(arr[c-'A'].left);
    cout << c;
    in(arr[c-'A'].right);
}

void pos(char c){
    if(c=='.') return;
    pos(arr[c-'A'].left);
    pos(arr[c-'A'].right);
    cout << c;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        char a, b, c;
        cin >> a >> b >> c;
        arr[a-'A'].left=b;
        arr[a-'A'].right=c;
    }
    pre('A'); cout << "\n";
    in('A'); cout << "\n";
    pos('A');
}