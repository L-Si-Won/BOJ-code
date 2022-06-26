#include <iostream>
#include <cstring>

using namespace std;

int n;
char arr[100][100];
int garo, sero;
bool visit[100][100];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++)
            arr[i][j]=s[j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[i][j]==false){
                if(arr[i][j]=='.'){
                    visit[i][j]=true;
                    j++;
                    int check=0;
                    while(j<n && arr[i][j]=='.'){
                        visit[i][j]=true;
                        j++;
                        check++;
                    }
                    if(check!=0) garo++;
                }
            }
        }
    }
    memset(visit, false, sizeof(visit));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visit[j][i]==false){
                if(arr[j][i]=='.'){
                    visit[j][i]=true;
                    j++;
                    int check=0;
                    while(j<n && arr[j][i]=='.'){
                        visit[j][i]=true;
                        j++;
                        check++;
                    }
                    if(check!=0) sero++;
                }
            }
        }
    }
    cout << garo << " " << sero;
}