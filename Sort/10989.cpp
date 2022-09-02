#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    int a[10001]= {0};
    int temp=0;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        a[temp]++;
    }

    for(int i = 1; i< 10001; i++)
        if(a[i]!=0)
            for(int j=0; j<a[i];j++)
                cout << i << "\n";
}
