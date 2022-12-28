#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int n, m;
unordered_set<string> memo;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        memo.insert(s);
    }

    while(m--){
        vector<string> keyword;
        string  s;

        cin >> s;

        //키워드 파싱하기
        string temp="";
        while(s.length()!=0){
            //첫글자가 , 이면 temp를 keyword에 추가하고
            //temp를 빈 문자열로 초기화한 후, 첫글자 제거
            if(s[0]==','){
                keyword.push_back(temp);
                temp="";
                s.erase(s.begin());
            }
            //첫글자가 문자면 첫글자를 temp에 추가하고
            //첫글자 제거
            else{
                temp+=s[0];
                s.erase(s.begin());
            }
        }
        keyword.push_back(temp); //마지막 키워드 추가

        //메모장에서 키워드 제거
        for(int i=0; i<keyword.size(); i++)
            if(memo.find(keyword[i])!=memo.end())
                memo.erase(keyword[i]);

        cout << memo.size() << "\n";
    }
}
