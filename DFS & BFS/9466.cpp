#include <iostream>
#include <cstring>

using namespace std;

int t, n, cnt, student[100001];
bool visit[100001];
bool complete[100001];

void dfs(int cur){
    int next = student[cur];
    visit[cur] = true;

    //방문x
    if (visit[next] == false)
        dfs(next);
    //방문O && 팀인지 판단 완료x
    else if (visit[next] == true && complete[next] == false){
        int temp = next;
        while (temp != cur){
            cnt++;
            temp = student[temp];
        }
        cnt++;
    }

    complete[cur] = true;
}

void init(){
    memset(visit, false, sizeof(visit));
    memset(complete, false, sizeof(complete));
    memset(student, 0, sizeof(student));
    cnt = 0;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> t;
    while(t--){
        init();

        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> student[i];

        //dfs
        for(int i = 1; i <= n; i++)
            if (visit[i] == false)
                dfs(i);

        //output
        cout << n - cnt << "\n";
    }
}
