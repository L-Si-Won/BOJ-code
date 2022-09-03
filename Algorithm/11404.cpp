#include <iostream>

using namespace std;

int n, m;
int dist[101][101];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    
    //모든 거리를 최대로 초기화
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i!=j) dist[i][j]=987654321;

    //입력받은대로 거리를 초기화
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        //더 짧은 거리를 저장
        if(dist[a][b]>c) dist[a][b]=c;
    }
        
    //플로이드 워셜 알고리즘
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                dist[j][k]=min(dist[j][k], dist[j][i]+dist[i][k]);

    //출력하기
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]==987654321)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
