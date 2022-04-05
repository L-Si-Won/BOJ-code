#include <iostream>
#include <vector>

using namespace std;

int d[1001];
int a[1001];
vector<int> temp[1001];
vector<int> sol;
void dp(int n)
{
    for(int i=1; i<n+1; i++)
    {
        d[i]=1;
        temp[i].push_back(a[i]);
        for(int j=i-1; j>0; j--)
        {
            if(a[i] > a[j])
            {
                if(d[i] < d[j]+1)
                {
                    d[i]=d[j]+1;
                    temp[i].clear(); //this command can erase
                    temp[i]=temp[j];
                    temp[i].push_back(a[i]);
                }
            }
        }
        if(sol.size() < temp[i].size())
            sol=temp[i];
    }
    cout << sol.size() << "\n";
    for(int i=0; i<sol.size(); i++)
        cout << sol[i] << " ";
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for(int i=1; i<n+1; i++)
        cin >> a[i];
    dp(n);
}