#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p, m;
pair<int, string> player[300];
vector<pair<int, string>> room[300];

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.second < b.second ? true : false;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> p >> m;
    for (int i = 0; i < p; i++)
        cin >> player[i].first >> player[i].second;

    for (int i = 0; i < p; i++){
        pair<int, string> cur_player = player[i];

        for (int j = 0; j < 300; j++){
            int player_cnt = room[j].size();
            
            if (player_cnt == 0){
                room[j].push_back(cur_player);
                break;
            }
            else if (player_cnt > 0 && player_cnt < m){
                pair<int, string> room_first = room[j][0];

                if (abs(room_first.first - cur_player.first) <= 10){
                    room[j].push_back(cur_player);
                    break;
                }
                else
                    continue;
            }
            else if (player_cnt == m)
                continue;
        }
    }

    for (int i = 0; i < 300; i++){
        if (room[i].size() == 0)
            break;

        if (room[i].size() == m)
            cout << "Started!\n";
        else
            cout << "Waiting!\n";

        sort(room[i].begin(), room[i].end(), cmp);
        
        for (int j = 0; j < room[i].size(); j++){
            cout << room[i][j].first << " ";
            cout << room[i][j].second << "\n";
        }
    }
}
