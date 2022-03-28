#include <iostream>

using namespace std;

int stack[100]={0};
int topindex=-1;

void push(int X)
{
    topindex++;
    stack[topindex]=X;
}

void pop()
{
    if(topindex==-1)
    {
        cout << "-1\n";
        return ;
    }
    cout << stack[topindex] << "\n";
    stack[topindex]=0;
    topindex--;
}

void size()
{
    cout << topindex+1 << "\n";
}

void empty()
{
    if(topindex == -1)
        cout << "1\n";
    else
        cout << "0\n";
}

void top()
{
    if(topindex == -1)
    {
        cout << "-1\n";
        return ;
    }
    cout << stack[topindex] << "\n";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string cmd="";
    int opr;
    for(int i=0; i<n; i++)
    {
        cin >> cmd;
        if(cmd == "push")
        {
            cin >> opr;
            push(opr);
        }
        else if(cmd == "pop")
            pop();
        else if(cmd == "size")
            size();
        else if(cmd == "empty")
            empty();
        else if(cmd == "top")
            top();
    }

}