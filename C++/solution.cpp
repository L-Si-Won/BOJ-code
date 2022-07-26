#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<char, int> card[5];
vector<int> score;

bool comp(pair<char, int> a, pair<char, int> b){
    return a.second < b.second ? true : false;
}

bool comp2(pair<int, int> a, pair<int, int> b){
    return a.second < b.second ? true : false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0; i<5; i++){
        char c;
        int n;
        cin >> c >> n;
        card[i]={c, n};
    }
    sort(card, card+5, comp);

    bool check=true;
    char color=card[0].first;
    for(int i=1; i<5; i++)
        if(color!=card[i].first) check=false; //색 확인

    if(check==true){ //5장 같은색
        bool con=true;
        int diff=card[0].second-card[1].second;
        for(int i=1; i<4; i++)
            if(card[i].second-card[i+1].second!=diff) con=false; //연속 확인
        if(con==true) score.push_back(900+card[4].second); //1
        else score.push_back(600+card[4].second); //4
    }
    else{
        bool con=true;
        int diff=card[0].second-card[1].second;
        for(int i=1; i<4; i++)
            if(card[i].second-card[i+1].second!=diff) con=false; //연속 확인
        if(con==true) score.push_back(500+card[4].second); //5

        vector<pair<int, int>> v; //카드숫자, 같은 숫자 수
        for(int i=0; i<5; i++){
            bool same=false;
            for(int j=0; j<v.size(); j++){
                if(card[i].second==v[j].first){
                    v[j].second++;
                    same=true;
                }
            }
            if(same==false) v.push_back({card[i].second, 1});
        }
        sort(v.begin(), v.end(), comp2);

        if(v.size()==2){ //4,1 or 3,2
            if(v[1].second==4)
                score.push_back(800+v[1].first); //2
            else
                score.push_back(700+v[1].first*10+v[0].first); //3
        }
        else if(v.size()==3){ //3,1,1 or 2,2,1
            if(v[2].second==3)
                score.push_back(400+v[2].first); //6
            else
                score.push_back(max(v[1].first, v[2].first)*10+min(v[1].first, v[2].first)+300); //7
        }
        else if(v.size()==4){ //2,1,1,1
            score.push_back(v[3].first+200); //8
        }
        else{ //1,1,1,1,1
            score.push_back(100+card[4].second);
        }
    }
    int MAX=0;
    for(int i=0; i<score.size(); i++)
        MAX=max(MAX, score[i]);
    cout << MAX;
}