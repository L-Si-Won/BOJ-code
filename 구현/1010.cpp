#include <iostream>

using namespace std;

int t, n, m;
int arr[1001][1001]; //arr[i][j] -> n=i이고 m=j일 때 경우의 수

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //초기화
    //mC0=1, mC1=m, mCm=1
    for(int i=0; i<30; i++){
        for(int j=1; j<30; j++){
            if(i==0) arr[i][j]=1;
            else if(i==1) arr[i][j]=j;
            else if(i==j) arr[i][j]=1;
        }
    }

    //mCn = m-1Cn + m-1Cn-1
    for(int i=1; i<30; i++){
        for(int j=1; j<30; j++){
            if(arr[i][j]==0)
                arr[i][j]=arr[i][j-1]+arr[i-1][j-1];
        }
    }

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << arr[n][m] << "\n";
    }
}
