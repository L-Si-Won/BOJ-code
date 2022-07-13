#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int k;
string n;

void solve(){
    queue<string> q;
    q.push(n);
    int MAX=0;

    for(int i=0; i<k; i++){
        set<string> visit;
        int qsize=q.size();

        for(int j=0; j<qsize; j++){ //q.size는 매번 변경되므로 변수로 고정해야함
            string cur=q.front();
            q.pop();

            for(int l=0; l<cur.size()-1; l++){
                for(int r=l+1; r<cur.size(); r++){
                    if(l==0 && cur[r]=='0') continue; //0으로 시작하는 수 예외 처리

                    swap(cur[l], cur[r]);
                    if(visit.find(cur)==visit.end()){ //새로운 수일 경우
                        if(i==k-1){ //k번째 교환 단계일 경우
                            MAX=max(MAX, stoi(cur));
                        }
                        q.push(cur);
                        visit.insert(cur);
                    }
                    swap(cur[l], cur[r]);
                }
            }
        }
    }
    cout << MAX;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    if(n.size()==1 || (n.size()==2 && stoi(n)%10==0)){
        cout << -1;
        return 0;
    }
    solve();
}