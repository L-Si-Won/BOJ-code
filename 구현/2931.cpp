#include <iostream>
#include <vector>

using namespace std;

int r, c;
char map[25][25], answer_block;
pair<int, int> M, Z, answer_point;
vector<pair<pair<int, int>, pair<int, int>>> break_point; //{{연결끊긴 곳}, {지워진 곳}}

void find_break_point(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if (map[i][j] == '|'){
                if (i - 1 >= 0 && map[i - 1][j] == '.')
                    break_point.push_back({{i, j}, {i - 1, j}});
                if (i + 1 < r && map[i + 1][j] == '.')
                    break_point.push_back({{i, j}, {i + 1, j}});
            }
            if (map[i][j] == '-'){
                if (j - 1 >= 0 && map[i][j - 1] == '.')
                    break_point.push_back({{i, j}, {i, j - 1}});
                if (j + 1 < c && map[i][j + 1] == '.')
                    break_point.push_back({{i, j}, {i, j + 1}});
            }
            if (map[i][j] == '+'){
                if (i - 1 >= 0 && map[i - 1][j] == '.')
                    break_point.push_back({{i, j}, {i - 1, j}});
                if (i + 1 < r && map[i + 1][j] == '.')
                    break_point.push_back({{i, j}, {i + 1, j}});
                if (j - 1 >= 0 && map[i][j - 1] == '.')
                    break_point.push_back({{i, j}, {i, j - 1}});
                if (j + 1 < c && map[i][j + 1] == '.')
                    break_point.push_back({{i, j}, {i, j + 1}});
            }
            if (map[i][j] == '1'){
                if (j + 1 < c && map[i][j + 1] == '.')
                    break_point.push_back({{i, j}, {i, j + 1}});
                if (i + 1 < r && map[i + 1][j] == '.')
                    break_point.push_back({{i, j}, {i + 1, j}});
            }
            if (map[i][j] == '2'){
                if (i - 1 >= 0 && map[i - 1][j] == '.')
                    break_point.push_back({{i, j}, {i - 1, j}});
                if (j + 1 < c && map[i][j + 1] == '.')
                    break_point.push_back({{i, j}, {i, j + 1}});
            }
            if (map[i][j] == '3'){
                if (j - 1 >= 0 && map[i][j - 1] == '.')
                    break_point.push_back({{i, j}, {i, j - 1}});
                if (i - 1 >= 0 && map[i - 1][j] == '.')
                    break_point.push_back({{i, j}, {i - 1, j}});
            }
            if (map[i][j] == '4'){
                if (j - 1 >= 0 && map[i][j - 1] == '.')
                    break_point.push_back({{i, j}, {i, j - 1}});
                if (i + 1 < r && map[i + 1][j] == '.')
                    break_point.push_back({{i, j}, {i + 1, j}});
            }
        }
    }
}

pair<int, int> find_M_or_Z(){
    int x = M.first;
    int y = M.second;
    if (x - 1 >= 0 &&
        (map[x - 1][y] == '|' || map[x - 1][y] == '+' || 
        map[x - 1][y] == '1' || map[x - 1][y] == '4'))
        return Z;
    if (x + 1 < r && 
        (map[x + 1][y] == '|' || map[x + 1][y] == '+' || 
        map[x + 1][y] == '2' || map[x + 1][y] == '3'))
        return Z;
    if (y - 1 >= 0 &&
        (map[x][y - 1] == '-' || map[x][y - 1] == '+' || 
        map[x][y - 1] == '1' || map[x][y - 1] == '2'))
        return Z;
    if (y + 1 < c &&
        (map[x][y + 1] == '-' || map[x][y + 1] == '+' || 
        map[x][y + 1] == '3' || map[x][y + 1] == '4'))
        return Z;
    return M;
}

void find_right_block(){
    answer_point = {break_point[0].second.first + 1, break_point[0].second.second + 1};

    if (break_point.size() == 1){
        pair<int, int> remain_point = find_M_or_Z();
        int rx = remain_point.first;
        int ry = remain_point.second;
        int ex = break_point[0].second.first;
        int ey = break_point[0].second.second;
        int bx = break_point[0].first.first;
        int by = break_point[0].first.second;
        pair<int, int> diff1 = {rx - ex, ry - ey};
        pair<int, int> diff2 = {bx - ex, by - ey};
        pair<int, int> sum = {diff1.first + diff2.first, diff1.second + diff2.second};
        
        if (sum.first == 1 && sum.second == 1)
            answer_block = '1';
        if (sum.first == -1 && sum.second == 1)
            answer_block = '2';
        if (sum.first == -1 && sum.second == -1)
            answer_block = '3';
        if (sum.first == 1 && sum.second == -1)
            answer_block = '4';
        if (sum.first == 0 && sum.second == 0){
            if (diff1.first == 1 || diff1.first == -1)
                answer_block = '|';
            else
                answer_block = '-';
        }
    }
    else if (break_point.size() == 2){
        int ex = break_point[0].second.first;
        int ey = break_point[0].second.second;
        int bx1 = break_point[0].first.first;
        int by1 = break_point[0].first.second;
        int bx2 = break_point[1].first.first;
        int by2 = break_point[1].first.second; 
        pair<int, int> diff1 = {bx1 - ex, by1 - ey};
        pair<int, int> diff2 = {bx2 - ex, by2 - ey};
        pair<int, int> sum = {diff1.first + diff2.first, diff1.second + diff2.second};

        if (sum.first == 1 && sum.second == 1)
            answer_block = '1';
        if (sum.first == -1 && sum.second == 1)
            answer_block = '2';
        if (sum.first == -1 && sum.second == -1)
            answer_block = '3';
        if (sum.first == 1 && sum.second == -1)
            answer_block = '4';
        if (sum.first == 0 && sum.second == 0){
            if (diff1.first == 1 || diff1.first == -1)
                answer_block = '|';
            else
                answer_block = '-';
        }
    }
    else if (break_point.size() == 4)
        answer_block = '+';
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string s;
        cin >> s;
        for(int j = 0; j < c; j++){
            map[i][j] = s[j];
            if (map[i][j] == 'M')
                M = {i, j};
            if (map[i][j] == 'Z')
                Z = {i, j};
        }
    }

    //find break_point and right block
    find_break_point();
    find_right_block();

    //output
    cout << answer_point.first << " " << answer_point.second << " " << answer_block;
}
