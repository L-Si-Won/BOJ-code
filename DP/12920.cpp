#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct something{
    int v;
    int c;
};

int n, m;
vector<something> thing;
int d[1500][10001];

void dp(){
    for(int i = thing[0].v; i <= m; i++)
        d[0][i] = thing[0].c;

    for(int i = 1; i < thing.size(); i++){
        for(int j = 0; j < thing[i].v; j++)
            d[i][j] = d[i - 1][j];

        for(int j = thing[i].v; j <= m; j++)
            d[i][j] = max(d[i - 1][j], d[i - 1][j - thing[i].v] + thing[i].c);
    }

    for(int i = 0; i < thing.size(); i++){
        for(int j = 0; j <= m; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int v, c, k;
        cin >> v >> c >> k;

        //bind thing
        int two = 1;
        while(k > 0){
            if (two > k)
                two = k;

            thing.push_back({v * two, c * two});

            k -= two;
            two *= 2;
        }
    }

    //dp
    dp();
    
    //output
    cout << d[thing.size() - 1][m];
}
