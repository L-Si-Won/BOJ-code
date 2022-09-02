#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    int b[a] = {0};
    for(int i = 0; i < a; i++)
        cin >> b[i];

    int temp = 0;
    for(int i = 0; i < a-1; i++)
    {
        for(int j = i+1; j < a; j++)
        {
            if(b[i] > b[j])
            {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    for(int i = 0; i < a; i++)
        cout << b[i] << endl;
}
