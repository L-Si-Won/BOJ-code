#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int e, s, m;
    cin >> e >> s >> m;
    int cnt=0;
    while(1)
    {
        if((e==0 && s==0) && m==0)
            break;
        if(e==0) e=15;
        if(s==0) s=28;
        if(m==0) m=19;
        e--;
        s--;
        m--;
        cnt++;
    }
    cout << cnt;
}
