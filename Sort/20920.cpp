#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
map<string, int> word;
vector<string> v;

bool cmp(string a, string b){
    if (a.length() == b.length() && word[a] == word[b]) {
        return a < b;
    }
    else if (word[a] == word[b]) {
        return a.length() > b.length();
    }
    return word[a] > word[b];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;

        if (s.length() < m)
            continue;
        
        if (word.find(s) == word.end()){
            word.insert({s, 1});
            v.push_back(s);
        }
        else
            word[s]++;
    }

    //sort
    sort(v.begin(), v.end(), cmp);

    //output
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
}
