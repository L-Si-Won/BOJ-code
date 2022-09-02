#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>


using namespace std;

int but[10];

bool possible(int i){
    if(i==0){
        if(but[i]==1) return false;
        else return true;
    }
    while(i){
        if(but[i%10]==1)
            return false;
        i=i/10;
    }
    return true;
}

int func(int n){
    int a=abs(n-100);
    int tmp;
    int MIN=a;
    for(int i=0; i<=1000001; i++){
        if(possible(i)){
            tmp=to_string(i).length();
            tmp+=abs(i-n);
            MIN=min(tmp, MIN);
        }
    }
    return MIN;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int b;
    cin >> n >> b;
    int digit[7];
    for(int i=0; i<b; i++){
        int fix;
        cin >> fix;
        but[fix]=1;
    }
    cout << func(n);
}
