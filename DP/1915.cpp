#include <iostream>

using namespace std;

int n, m;
int arr[1001][1001];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        for(int j=1; j<=m; j++)
            arr[i][j]=s[j-1]-'0';
    }
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(arr[i][j]!=0)
                arr[i][j]=min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1]))+1;
    
    int answer=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            answer=max(answer, arr[i][j]*arr[i][j]);
    
    cout << answer;
}
