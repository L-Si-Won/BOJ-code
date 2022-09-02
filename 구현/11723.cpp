#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
string cmd;
int x;
vector<int> v;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(cmd=="all" || cmd=="empty"){
            if(cmd=="all"){
                v.clear();
                for(int j=1; j<21; j++)
                    v.push_back(j);
            }
            if(cmd=="empty")
                v.clear();
        }
        else{
            cin >> x;
            if(cmd=="add"){
                int check=0;
                for(int j=0; j<v.size(); j++)
                    if(v[j]==x)
                        check++;
                if(check==0)
                    v.push_back(x);
            }
            if(cmd=="remove"){
                int temp=0;
                for(int j=0; j<v.size(); j++){
                    if(v[j]==x){
                        v[j]=0;
                        temp=j;
                        break;
                    }
                }
                for(int j=temp; j<v.size(); j++)
                    v[j]=v[j+1];
                if(v.size()>0)
                    v.resize(v.size()-1);
            }
            if(cmd=="check"){
                int check=0;
                for(int j=0; j<v.size(); j++)
                    if(v[j]==x)
                        check++;
                if(check>0) cout << "1\n";
                else cout << "0\n";
            }
            if(cmd=="toggle"){
                int check=0;
                int temp=0;
                for(int j=0; j<v.size(); j++){
                    if(v[j]==x){
                        v[j]=0;
                        temp=j;
                        check++;
                        break;
                    }
                }
                if(check>0){
                    for(int j=temp; j<v.size(); j++)
                        v[j]=v[j+1];
                    v.resize(v.size()-1);
                }
                if(check==0)
                    v.push_back(x);
            }
        }
    }
}
