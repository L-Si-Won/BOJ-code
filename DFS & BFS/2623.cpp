#include <iostream>
#include <queue>

using namespace std;

int n, m;
bool child[1001][1001];
int parent[1001];

void bfs(){
    queue<int> q;
    vector<int> answer;

    //push node who no parent
    for(int i = 1; i <= n; i++)
        if (parent[i] == 0)
            q.push(i);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        answer.push_back(cur);

        for(int i = 1; i <= n; i++){
            if (child[cur][i] == true){
                parent[i]--;
    
                if (parent[i] == 0)
                    q.push(i);
            }
        }
    }

    //output
    if (answer.size() != n)
        cout << 0;
    else
        for(int i = 0; i <answer.size(); i++)
            cout << answer[i] << "\n";
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int singer = 0;
        cin >> singer;
        
        int temp;
        cin >> temp;
        for(int j = 0; j < singer - 1; j++){
            int temp2;
            cin >> temp2;

            //중복 간선은 무시
            if (child[temp][temp2] == false){
                child[temp][temp2] = true;
                parent[temp2]++;
            }

            temp = temp2;
        }
    }

    bfs();
}
