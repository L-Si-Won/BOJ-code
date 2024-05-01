#include <iostream>
#include <cstring>

using namespace std;

int T, n, k, t, m;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T--){
        cin >> n >> k >> t >> m;

        // data[i][j]:i팀의 j문제의 최종점수
        int data[101][101];
        int score[101], cnt[101], time[101];
        memset(data, 0, sizeof(data));
        memset(score, 0, sizeof(score));
        memset(cnt, 0, sizeof(cnt));
        memset(time, 0, sizeof(time));

        for (int cur_time = 0; cur_time < m; cur_time++){
            int i, j, s;
            cin >> i >> j >> s;

            data[i][j] = max(data[i][j], s);
            cnt[i]++;
            time[i] = cur_time;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++)
                score[i] += data[i][j];
        
        int rank = 1;
        for (int i = 1; i <= n; i++){
            if (i == t)
                continue;
            
            if (score[t] < score[i])
                rank++;
            else if (score[t] == score[i]){
                if (cnt[t] > cnt[i])
                    rank++;
                else if (cnt[t] == cnt[i]){
                    if (time[t] > time[i])
                        rank++;
                }
                else
                    continue;
            }
            else
                continue;
        }

        cout << rank << "\n";
    }
}
