#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, answer[50001];
vector<int> v1, v2;
//v1 : v1's element i is answer[i] = 1
//v2 : v2's element i is answer[i] = 2

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;

    //init
    for (int i = 0; i <= 50000; i++)
        answer[i] = 4;

    //answer[i] = 1
    for (int i = 1; i <= sqrt(50000); i++){
        answer[i * i] = 1;
        v1.push_back(i * i);
    }

    //answer[i] = 2
    for (int i = 0; i < v1.size(); i++){
        for (int j = i; j < v1.size(); j++){
            if (v1[i] + v1[j] <= 50000){
                answer[v1[i] + v1[j]] = min(answer[v1[i] + v1[j]], 2);
                v2.push_back(v1[i] + v1[j]);
            }
        }
    }
    
    //answer[i] = 3
    for (int i = 0; i < v1.size(); i++)
        for (int j = 0; j < v2.size(); j++)
            if (v1[i] + v2[j] <= 50000)
                answer[v1[i] + v2[j]] = min(answer[v1[i] + v2[j]], 3);

    //output
    cout << answer[n];
}
