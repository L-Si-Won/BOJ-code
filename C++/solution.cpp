#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    queue<int>q;
    int que[n];
    for(int i=1; i<n+1; i++)
        q.push(i);
    for(int i=0; i<n; i++)
    {
        int temp;
        for(int j=0; j<k-1; j++)
        {
            temp=q.front();
            q.pop();
            q.push(temp);
        }
        que[i]=q.front();
        q.pop();
    }
    cout << "<";
    for(int i=0; i<n; i++)
    {
        if(i==0)
            cout << que[i];
        else
            cout << ", " << que[i];
    }
    cout << ">";
}