#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int P[N] = {0};
    for(int i = 0; i < N; i++)
        cin >> P[i];
    int temp = 0;
    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(P[i] > P[j])
            {
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            sum += P[j];
        }
    }
    cout << sum;
}
