#include <iostream>
#include <algorithm>

using namespace std;

int d[505][505];
int sum;
int MAX;

void reset()
{
    MAX=max(MAX, sum);
    sum=0;
}
void check(int i, int j)
{
    for(int a=i; a<=i+3; a++) //세로모양
        sum += d[a][j];
    reset();

    for(int a=j; a<=j+3; a++) //가로모양
        sum += d[i][a];
    reset();

    for(int a=i; a<=i+1; a++) //네모모양
        for(int b=j; b<=j+1; b++)
            sum += d[a][b];
    reset();

    //ㅗ모양
    sum += d[i][j] + d[i-1][j-1] + d[i-1][j] + d[i-1][j+1];
    reset();
    sum += d[i][j] + d[i+1][j-1] + d[i+1][j] + d[i+1][j+1];
    reset();
    sum += d[i][j] + d[i-1][j-1] + d[i][j-1] + d[i+1][j-1];
    reset();
    sum += d[i][j] + d[i-1][j+1] + d[i][j+1] + d[i+1][j+1];
    reset();

    // ㄱ모양
    sum += d[i][j] + d[i+1][j] + d[i+2][j] + d[i+2][j+1];
    reset();
    sum += d[i][j] + d[i][j+1] + d[i][j+2] + d[i+1][j+2];
    reset();
    sum += d[i][j] + d[i][j+1] + d[i+1][j+1] + d[i+2][j+1];
    reset();
    sum += d[i][j] + d[i+1][j] + d[i+1][j+1] + d[i+1][j+2];
    reset();
    sum += d[i][j] + d[i+1][j] + d[i+2][j] + d[i+2][j-1];
    reset();
    sum += d[i][j] + d[i][j+1] + d[i][j+2] + d[i-1][j+2];
    reset();
    sum += d[i][j] + d[i-1][j] + d[i-1][j+1] + d[i-1][j+2];
    reset();
    sum += d[i][j] + d[i][j-1] + d[i+1][j-1] + d[i+2][j-1];
    reset();

    //번개모양
    sum += d[i][j] + d[i+1][j] + d[i+1][j+1] + d[i+2][j+1];
    reset();
    sum += d[i][j] + d[i+1][j] + d[i+1][j-1] + d[i+2][j-1];
    reset();
    sum += d[i][j] + d[i][j+1] + d[i+1][j+1] + d[i+1][j+2];
    reset();
    sum += d[i][j] + d[i][j+1] + d[i-1][j+1] + d[i-1][j+2];
    reset();
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
            cin >> d[i][j];
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            check(i, j);
        }
    }
    cout << MAX;
}
