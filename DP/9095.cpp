#include <iostream>
#include <vector>

using namespace std;

vector<int>v(11,0);

int dp(vector<int> &v, int i)
{
    if(i==1) return 1;
    if(i==2) return 2;
    if(i==3) return 4;
    if(v[i]!=0) return v[i];
    v.push_back(dp(v,i-1)+dp(v,i-2)+dp(v,i-3));
    return v.back();
}

int main()
{
    int test;
    cin >> test;
    int n;
    for(int i=0; i<test; i++)
    {
        cin >> n;
        cout << dp(v, n) << "\n";
    }
}
