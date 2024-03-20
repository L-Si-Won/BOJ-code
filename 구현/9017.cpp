#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int t, n, arr[1000];
int quali[201], team[201][6], team_idx[201];
vector<pair<int, int>> win;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> t;

    while (t--){
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        //check qualification
        for (int i = 0; i < n; i++)
            quali[arr[i]]++;
        
        //assign score
        int temp = 1;
        for (int i = 0; i < n; i++)
            if (quali[arr[i]] == 6)
                team[arr[i]][team_idx[arr[i]]++] = temp++;
        
        //find winner
        for (int i = 0; i < 201; i++){
            if (quali[i] == 6){
                int score = team[i][0] + team[i][1] + team[i][2] + team[i][3];

                if (win.empty() == true)
                    win.push_back({i, score});
                else{
                    if (score < win[0].second){
                        win.clear();
                        win.push_back({i, score});
                    }
                    else if (score == win[0].second)
                        win.push_back({i, score});
                }
            }
        }

        //output
        if (win.size() == 1){
            cout << win[0].first << "\n";
        }
        else{
            pair<int, int> winner = {win[0].first, team[win[0].first][4]};

            for (int i = 1; i < win.size(); i++)
                if (team[win[i].first][4] < winner.second)
                    winner = {win[i].first, team[win[i].first][4]};

            cout << winner.first << "\n";
        }

        //init
        memset(quali, 0, sizeof(int) * 201);
        memset(team, 0, sizeof(int) * 201 * 6);
        memset(team_idx, 0, sizeof(int) * 201);
        win.clear();
    }
}
