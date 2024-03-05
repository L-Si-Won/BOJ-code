#include <iostream>
#include <algorithm>

using namespace std;

struct player{
    int b;
    int p;
    int q;
    int r;
    int mul;
    int sum;
};

int n;
player p[100];

bool cmp(player p1, player p2){
    
    if (p1.mul > p2.mul)
        return false;
    else if (p1.mul < p2.mul)
        return true;
    else{
        if (p1.sum > p2.sum)
            return false;
        else if (p1.sum < p2.sum)
            return true;
        else{
            if (p1.b > p2.b)
                return false;
            else
                return true;
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> p[i].b >> p[i].p >> p[i].q >> p[i].r;
        p[i].mul = p[i].p * p[i].q * p[i].r;
        p[i].sum = p[i].p + p[i].q + p[i].r;
    }

    sort(p, p + n, cmp);

    for (int i = 0; i < 3; i++)
        cout << p[i].b << " ";
}
