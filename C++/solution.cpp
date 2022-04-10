#include <iostream>
#include <algorithm>

using namespace std;

long long d[101];
int temp[9]={0,0,1,7,4,2,0,8,10};
void dp()
{
    for(int i=2; i<9; i++)
        d[i]=temp[i];
    d[6]=6;
    for(int i=9; i<101; i++) //가장 작은 수
    {
        d[i]=d[i-2]*10+temp[2];
        for(int j=3; j<8; j++)
            d[i]=min(d[i-j]*10+temp[j], d[i]);
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;
    dp();
    for(int i=0; i<test_case; i++)
    {
        int n;
        cin >> n;
        cout << d[n] << " ";
        if(n%2==0)
        {
            for(int j=0; j<n/2; j++)
                cout << "1";
            cout << "\n";
        }
        else
        {
            cout << "7";
            for(int j=0; j<(n-1)/2-1; j++)
                cout << "1";
            cout << "\n";
        }
    }
}