#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
map<int, string> dict1;
map<string, int> dict2;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	//input
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		string s;
		cin >> s;

		dict1.insert({i, s});
		dict2.insert({s, i});
	}
	
	//find answer
	while (m--){
		string s;
		cin >> s;

		int num;
		string name;
		if (s[0] >= '0' && s[0] <= '9'){ //input is number
			num = atoi(&s[0]);
			name = (*dict1.find(num)).second;

			//output
			cout << name << "\n";
		}
		else{ //input is character
			name = s;
			num = (*dict2.find(name)).second;
			
			//output
			cout << num << "\n";
		}
	}
}
