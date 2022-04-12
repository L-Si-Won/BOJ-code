#include <iostream>
#include <algorithm>

using namespace std;

char a[51][51];
int MAX;
int n;
void check()
{
    int cnt=1;
    int temp_max=1;
    for(int i=1; i<n+1; i++){
        cnt=1;
        for(int j=1; j<n; j++){
            if(a[i][j] == a[i][j+1])
                cnt++;
            else{
                temp_max=max(temp_max, cnt);
                cnt=1;
            }
        }
        temp_max=max(temp_max, cnt);
    }
    for(int i=1; i<n+1; i++){
        cnt=1;
        for(int j=1; j<n; j++){
            if(a[j][i] == a[j+1][i])
                cnt++;
            else{
                temp_max=max(temp_max, cnt);
                cnt=1;
            }
        }
        temp_max=max(temp_max, cnt);
    }
    MAX=max(MAX, temp_max);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<n+1; j++)
            cin >> a[i][j];
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n; j++){
            swap(a[i][j], a[i][j+1]);
            check();
            swap(a[i][j], a[i][j+1]);
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n; j++){
            swap(a[j][i], a[j+1][i]);
            check();
            swap(a[j][i], a[j+1][i]);
        }
    }
    cout << MAX;
}