#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int n, m;
map<string, int> man;
vector<string> answer;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        man.insert({s, 1});
    }
    for(int i=0; i<m; i++){
        string s;
        cin >> s;
        if(man.find(s)==man.end()) man.insert({s, 1});
        else man[s]++;
    }
    for(auto i=man.begin(); i!=man.end(); i++)
        if(i->second==2) answer.push_back(i->first);
    
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << "\n";
}
