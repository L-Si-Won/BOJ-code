#include <iostream>
#include <cmath>

using namespace std;

int n, k;
int arr[1001][1001]; //arr[i][j] = iCj

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    //nC0=1
    if(k==0){
        cout << 1;
        return 0;
    }

    //nCn=1, nC1=n
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(i==j) arr[i][j]=1;
            if(j==1) arr[i][j]=i;
        }
    }

    //nCr = n-1Cr + n-1Cr-1
    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
            if(arr[i][j]==0)
                arr[i][j]=(arr[i-1][j]+arr[i-1][j-1])%10007;

    //출력
    cout << arr[n][k];
}
