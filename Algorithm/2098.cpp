#include <iostream>
#define INF 2e9

using namespace std;

int n, w[16][16], answer;
int cost[16][65536];

int tsp(int cur, int visit){
    if (cost[cur][visit] != 0) //해당 경로의 최솟값이 존재
        return cost[cur][visit];

    if (visit == (1 << n) - 1){ //모든 정점 방문 완료
        if (w[cur][0] != 0)
            return w[cur][0];
        else
            return INF;
    }

    int min_cost = INF;
    for(int i = 0; i < n; i++){
        int next = i;
        int nvisit = visit | (1 << next);

        // cur->next 경로 존재 && next 방문x
        if (w[cur][next] != 0 && (visit & (1 << next)) == 0)
            min_cost = min(min_cost, w[cur][next] + tsp(next, nvisit));
    }

    cost[cur][visit] = min_cost;
    return min_cost;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int  j = 0; j < n; j++)
            cin >> w[i][j];

    //tsp algorithm
    answer = tsp(0, 1);

    //output
    cout << answer;
}
