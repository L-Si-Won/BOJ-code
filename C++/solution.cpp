#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int k;
char arr[9];
int a[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int temp[10];
bool visit[10];
int MIN[10]={10,10,10,10,10,10,10,10,10,10};
int MAX[10];


bool check(){
    for(int i=0; i<k; i++){
        if(arr[i]=='>'){
            if(temp[i] > temp[i+1])
                continue;
            else
                return false;
        }
        else if(arr[i]=='<'){
            if(temp[i] < temp[i+1])
                continue;
            else
                return false;
        }
    }
    return true;
}

void Min_Max(){
    int i=0;
    while(1){
        if(MIN[i]>temp[i]){
            for(int j=0; j<k+1; j++)
                MIN[j]=temp[j];
            break;
        }
        else if(MIN[i]==temp[i])
            i++;
        else
            break;
    }
    i=0;
    while(1){
        if(MAX[i]<temp[i]){
            for(int j=0; j<k+1; j++)
                MAX[j]=temp[j];
            break;
        }
        else if(MAX[i]==temp[i])
            i++;
        else
            break;
    }
}

void solve(int cnt){
    if(cnt==k+1){
        if(check())
            Min_Max();
        return ;
    }
    for(int i=0; i<10; i++){
        if(visit[i]==false){
            visit[i]=true;
            temp[cnt]=a[i];
            solve(cnt+1);
            visit[i]=false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> k;
    for(int i=0; i<k; i++)
        cin >> arr[i];
    solve(0);
    
    string s_max;
    string s_min;
    for(int i=0; i<k+1; i++){
        s_max+=to_string(MAX[i]);
        s_min+=to_string(MIN[i]);
    }
    cout << s_max << "\n" << s_min;
}