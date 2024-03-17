#include <iostream>
#include <set>

using namespace std;

int n, num, cnt, answer;
char game;
set<string> player;


int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> game;

    if (game == 'Y') num = 2;
    else if (game == 'F') num = 3;
    else num = 4;

    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        if (player.find(s) == player.end()){
            player.insert(s);
            cnt++;

            if (cnt + 1== num){
                answer++;
                cnt = 0;
            }
        }
    }

    cout << answer;
}
