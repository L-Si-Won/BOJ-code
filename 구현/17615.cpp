#include <iostream>

using namespace std;

int n, temp, answer = 2e9;
bool flag;
string s;
char ball[1000000];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        ball[i] = s[i];
    }

    //move red to right
    flag = false;
    temp = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (ball[i] == 'B') {
            flag = true;
        }
        if (flag && ball[i] == 'R') {
            temp++;
        }
    }
    answer = min(answer, temp);

    //move blue to right
    flag = false;
    temp = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (ball[i] == 'R') {
            flag = true;
        }
        if (flag && ball[i] == 'B') {
            temp++;
        }
    }
    answer = min(answer, temp);

    //move red to left
    flag = false;
    temp = 0;
    for (int i = 0; i < n; i++) {
        if (ball[i] == 'B') {
            flag = true;
        }
        if (flag && ball[i] == 'R') {
            temp++;
        }
    }
    answer = min(answer, temp);

    //move blue to left
    flag = false;
    temp = 0;
    for (int i = 0; i < n; i++) {
        if (ball[i] == 'R') {
            flag = true;
        }
        if (flag && ball[i] == 'B') {
            temp++;
        }
    }
    answer = min(answer, temp);

    cout << answer;
}
