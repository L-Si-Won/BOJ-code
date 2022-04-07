#include <iostream>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int x1, y1, r1, x2, y2, r2;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        if(x1==x2 && y1==y2)
        {
            if(r1==r2)
                ans=-1;
            else
                ans=0;
        }
        else
        {
            ans=2;
            if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==(r1+r2)*(r1+r2))
                ans=1;
            if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)==(r2-r1)*(r2-r1))
                ans=1;
            if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) > (r1+r2)*(r1+r2))
                ans=0;
            if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) < (r1-r2)*(r1-r2))
                ans=0;
        }
        cout << ans << "\n";
    }
}