#include <iostream>
#include <queue>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    queue<int>q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "push")
        {
            int opr;
            cin >> opr;
            q.push(opr);
        }
        if(cmd == "pop")
        {
            if(!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << "-1\n";
        }
        if(cmd == "size")
        {
            cout << q.size() << "\n";
        }
        if(cmd == "empty")
        {
            if(!q.empty())
                cout << "0\n";
            else
                cout << "1\n";
        }
        if(cmd == "front")
        {
            if(!q.empty())
                cout << q.front() << "\n";
            else
                cout << "-1\n";
        }
        if(cmd == "back")
        {
            if(!q.empty())
                cout << q.back() << "\n";
            else
                cout << "-1\n";
        }
    }
}