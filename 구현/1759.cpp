#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[15];
char temp[15];
bool visit[15];

void dfs(int cnt, int num){
    if(cnt==L){
        int vowel=0;
        int cons=0;
        for(int i=0; i<L; i++){
            if(temp[i]=='a' || temp[i]=='e' || temp[i]=='i' || temp[i]=='o' || temp[i]=='u')
                vowel++;
            else
                cons++;
        }
        if(vowel<1 || cons<2)
            return ;

        for(int i=0; i<L; i++)
            cout << temp[i];
        cout << "\n";
        return ;
    }

    for(int i=num; i<C; i++){
        if(visit[i]==false){
            visit[i]=true;
            temp[cnt]=arr[i];
            dfs(cnt+1, i+1);
            visit[i]=false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> L >> C;
    for(int i=0; i<C; i++)
        cin >> arr[i];
    sort(arr, arr+C);
    dfs(0, 0);
}
