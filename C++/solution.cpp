#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a[9];
    int sum=0;
    for(int i=0; i<9; i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    int one, two;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            int temp=sum;
            if(i!=j)
            {
                temp=temp-a[i]-a[j];
                if(temp==100)
                {
                    one=i;
                    two=j;
                    break;
                }
            }
        }
    }
    vector<int> real;
    for(int i=0; i<9; i++)
        if(i!=one && i!=two)
            real.push_back(a[i]);
    sort(real.begin(), real.end());
    for(int i=0; i<7; i++)
        cout << real[i] << "\n";
}