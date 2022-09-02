#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    deque<int>d;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string cmd;
        cin >> cmd;
        if(cmd == "push_front")
        {
            int opr;
            cin >> opr;
            d.push_front(opr);
        }
        if(cmd == "push_back")
        {
            int opr;
            cin >> opr;
            d.push_back(opr);
        }
        if(cmd == "pop_front")
        {
            if(d.empty()==true)
                cout << "-1\n";
            else
            {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        if(cmd == "pop_back")
        {
            if(d.empty()==true)
                cout << "-1\n";
            else
            {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        if(cmd == "size")
        {
            cout << d.size() << "\n";
        }
        if(cmd == "empty")
        {
            if(d.empty()==true)
                cout << "1\n";
            else
                cout << "0\n";
        }
        if(cmd == "front")
        {
            if(d.empty()==true)
                cout << "-1\n";
            else
                cout << d.front() << "\n";
        }
        if(cmd == "back")
        {
            if(d.empty()==true)
                cout << "-1\n";
            else
                cout << d.back() << "\n";
        }
    }
}
