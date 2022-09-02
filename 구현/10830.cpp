#include <iostream>

using namespace std;

int a[5][5];
int ans[5][5];
int temp[5][5];
long long n, b;

void multi(int a1[5][5], int a2[5][5]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp[i][j]=0;
            for(int k=0; k<n; k++)
                temp[i][j]+=(a1[i][k]*a2[k][j]);
            temp[i][j]%=1000;
        }
    }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a1[i][j]=temp[i][j];
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> b;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
        ans[i][i]=1;
    }

    while(b>0){
        if(b%2==1)
            multi(ans, a);
        multi(a, a);
        b/=2;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}
