#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m ,h; //세로 가로 높이
int arr[100][100][100];
int dp[100][100][100];
bool visit[100][100][100];
int dm[]={1, -1, 0, 0, 0, 0}; //가로이동
int dn[]={0, 0, 1, -1, 0, 0}; //세로이동
int dh[]={0, 0, 0, 0, 1, -1}; //높이이동

void solve(){
    queue<tuple<int, int, int>> q;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[i][j][k]==1){
                    q.push({i, j, k});
                    visit[i][j][k]=true;
                }
            }
        }
    }

    while(!q.empty()){
        int cm=get<2>(q.front());
        int cn=get<1>(q.front());
        int ch=get<0>(q.front());
        q.pop();

        for(int i=0; i<6; i++){
            int nm=cm+dm[i];
            int nn=cn+dn[i];
            int nh=ch+dh[i];
            if(nm>=0 && nn>=0 && nh>=0 && nm<m && nn<n && nh<h){
                if(visit[nh][nn][nm]==false && arr[nh][nn][nm]==0){
                    q.push({nh, nn, nm});
                    arr[nh][nn][nm]=1;
                    dp[nh][nn][nm]=dp[ch][cn][cm]+1;
                    visit[nh][nn][nm]=true;
                }
            }
        }
    }
}

void check_zero(){
    int cnt=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[i][j][k]==1)
                    cnt++;
            }
        }
    }
    if(cnt==n*m*h){
        cout << "0";
        exit(0);
    }
}

void check_minus(){
    int cnt_zero=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(arr[i][j][k]==0)
                    cnt_zero++;
            }
        }
    }
    if(cnt_zero>0){
        cout << "-1";
        exit(0);
    }
}

int ans(){
    int MAX=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                MAX=max(MAX, dp[i][j][k]);
            }
        }
    }
    return MAX;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> h;
    for(int i=0; i<h; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<m; k++)
                cin >> arr[i][j][k];
    check_zero();

    solve();
    check_minus();

    cout << ans();
}
