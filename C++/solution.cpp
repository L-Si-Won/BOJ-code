#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int n, m; //행 열
char arr[10][10];
pair<int,int> Red, Blue; //초기 R, B 위치

void solve(){
    queue<tuple<int, int, int>> R; //n, m, 움직인 횟수
    queue<tuple<int, int, int>> B;
    queue<int> dir; //좌(0), 우(1), 상(2), 하(3)
    R.push({Red.first, Red.second, 0});
    B.push({Blue.first, Blue.second, 0});
    dir.push(-1);

    while(1){
        int rx=get<0>(R.front());
        int ry=get<1>(R.front());
        int rcnt=get<2>(R.front());
        int bx=get<0>(B.front());
        int by=get<1>(B.front());
        int bcnt=get<2>(B.front());
        int pre_dir=dir.front();
        R.pop();
        B.pop();
        dir.pop();

        if(rcnt+1>10 || bcnt+1>10){
            cout << "-1";
            exit(0);
        }

        for(int i=0; i<4; i++){
            if(i==0){ //왼쪽 기울이기
                if(pre_dir==1 || pre_dir==i) continue;
                int rny=ry;
                int bny=by;
                if(rx==bx){ //같은 행에 있을 경우
                    if(ry<by){ //빨강이 더 왼쪽에 있는 경우
                        while(arr[rx][rny-1]!='#' && arr[rx][rny-1]!='O')
                            rny--;
                        while(arr[bx][bny-1]!='#' && arr[bx][bny-1]!='O' && bny-1!=rny)
                            bny--;
                        if(arr[rx][rny-1]=='O'){
                            if(rny+1==bny) continue; //빨강 통과 후 파랑이 뒤따라 들어가는 경우
                            cout << rcnt+1;
                            exit(0);
                        }
                        if(arr[bx][bny-1]!='O'){
                            R.push({rx, rny, rcnt+1});
                            B.push({bx, bny, bcnt+1});
                            dir.push(i);
                        }
                    }
                    else{ //파랑이 더 왼쪽에 있는 경우
                        while(arr[bx][bny-1]!='#' && arr[bx][bny-1]!='O')
                            bny--;
                        while(arr[rx][rny-1]!='#' && arr[rx][rny-1]!='O' && rny-1!=bny)
                            rny--;
                        if(arr[bx][bny-1]!='O'){
                            R.push({rx, rny, rcnt+1});
                            B.push({bx, bny, bcnt+1});
                            dir.push(i);
                        }
                        if(arr[rx][rny-1]=='O'){
                            cout << rcnt+1;
                            exit(0);
                        }
                    }
                }
                else{ //다른 행에 있을 경우
                    while(arr[rx][rny-1]!='#' && arr[rx][rny-1]!='O')
                        rny--;
                    while(arr[bx][bny-1]!='#' && arr[bx][bny-1]!='O')
                        bny--;
                    if(arr[rx][rny-1]=='O'){
                        cout << rcnt+1;
                        exit(0);
                    }
                    if(arr[bx][bny-1]!='O'){
                        R.push({rx, rny, rcnt+1});
                        B.push({bx, bny, bcnt+1});
                        dir.push(i);
                    }
                }
            }
            else if(i==1){ //오른쪽 기울이기
                if(pre_dir==0 || pre_dir==i) continue;
                int rny=ry;
                int bny=by;
                if(rx==bx){ //같은 행에 있을 경우
                    if(ry<by){ //빨강이 더 왼쪽에 있는 경우
                        while(arr[bx][bny+1]!='#' && arr[bx][bny+1]!='O')
                            bny++;
                        while(arr[rx][rny+1]!='#' && arr[rx][rny+1]!='O' && rny+1!=bny)
                            rny++;
                        if(arr[rx][rny+1]=='O'){
                            cout << rcnt+1;
                            exit(0);
                        }
                        if(arr[bx][bny+1]!='O'){
                            R.push({rx, rny, rcnt+1});
                            B.push({bx, bny, bcnt+1});
                            dir.push(i);
                        }
                    }
                    else{ //파랑이 더 왼쪽에 있는 경우
                        while(arr[rx][rny+1]!='#' && arr[rx][rny+1]!='O')
                            rny++;
                        while(arr[bx][bny+1]!='#' && arr[bx][bny+1]!='O' && bny+1!=rny)
                            bny++;
                        if(arr[bx][bny+1]!='O'){
                            R.push({rx, rny, rcnt+1});
                            B.push({bx, bny, bcnt+1});
                            dir.push(i);
                        }
                        if(arr[rx][rny+1]=='O'){
                            if(rny-1==bny) continue; //빨강 통과 후 파랑이 뒤따라 들어가는 경우
                            cout << rcnt+1;
                            exit(0);
                        }
                    }
                }
                else{ //다른 행에 있을 경우
                    while(arr[rx][rny+1]!='#' && arr[rx][rny+1]!='O')
                        rny++;
                    while(arr[bx][bny+1]!='#' && arr[bx][bny+1]!='O')
                        bny++;
                    if(arr[rx][rny+1]=='O'){
                        cout << rcnt+1;
                        exit(0);
                    }
                    if(arr[bx][bny+1]!='O'){
                        R.push({rx, rny, rcnt+1});
                        B.push({bx, bny, bcnt+1});
                        dir.push(i);
                    }
                }
            }
            else if(i==2){ //위쪽 기울이기
                if(pre_dir==3 || pre_dir==i) continue;
                int rnx=rx;
                int bnx=bx;
                if(ry==by){ //같은 열에 있을 경우
                    if(rx<bx){ //빨강이 더 위쪽에 있는 경우
                        while(arr[rnx-1][ry]!='#' && arr[rnx-1][ry]!='O')
                            rnx--;
                        while(arr[bnx-1][by]!='#' && arr[bnx-1][by]!='O' && bnx-1!=rnx)
                            bnx--;
                        if(arr[rnx-1][ry]=='O'){
                            if(rnx+1==bnx) continue; //빨강 통과 후 파랑이 뒤따라 들어가는 경우
                            cout << rcnt+1;
                            exit(0);
                        }
                        if(arr[bnx-1][by]!='O'){
                            R.push({rnx, ry, rcnt+1});
                            B.push({bnx, by, bcnt+1});
                            dir.push(i);
                        }
                    }
                    else{ //파랑이 더 위쪽에 있는 경우
                        while(arr[bnx-1][by]!='#' && arr[bnx-1][by]!='O')
                            bnx--;
                        while(arr[rnx-1][ry]!='#' && arr[rnx-1][ry]!='O' && rnx-1!=bnx)
                            rnx--;
                        if(arr[rnx-1][ry]=='O'){
                            cout << rcnt+1;
                            exit(0);
                        }
                        if(arr[bnx-1][by]!='O'){
                            R.push({rnx, ry, rcnt+1});
                            B.push({bnx, by, bcnt+1});
                            dir.push(i);
                        }
                    }
                }
                else{ //다른 열에 있을 경우
                    while(arr[rnx-1][ry]!='#' && arr[rnx-1][ry]!='O')
                        rnx--;
                    while(arr[bnx-1][by]!='#' && arr[bnx-1][by]!='O')
                        bnx--;
                    if(arr[rnx-1][ry]=='O'){
                        cout << rcnt+1;
                        exit(0);
                    }
                    if(arr[bnx-1][by]!='O'){
                        R.push({rnx, ry, rcnt+1});
                        B.push({bnx, by, bcnt+1});
                        dir.push(i);
                    }
                }
            }
            else{ //아래쪽 기울이기
                if(pre_dir==2 || pre_dir==i) continue;
                int rnx=rx;
                int bnx=bx;
                if(ry==by){ //같은 열에 있을 경우
                    if(rx<bx){ //빨강이 더 위쪽에 있는 경우
                        while(arr[bnx+1][by]!='#' && arr[bnx+1][by]!='O')
                            bnx++;
                        while(arr[rnx+1][ry]!='#' && arr[rnx+1][ry]!='O' && rnx+1!=bnx)
                            rnx++;
                        if(arr[rnx+1][ry]=='O'){
                            cout << rcnt+1;
                            exit(0);
                        }
                        if(arr[bnx+1][by]!='O'){
                            R.push({rnx, ry, rcnt+1});
                            B.push({bnx, by, bcnt+1});
                            dir.push(i);
                        }
                    }
                    else{ //파랑이 더 위쪽에 있는 경우
                        while(arr[rnx+1][ry]!='#' && arr[rnx+1][ry]!='O')
                            rnx++;
                        while(arr[bnx+1][by]!='#' && arr[bnx+1][by]!='O' && bnx+1!=rnx)
                            bnx++;
                        if(arr[rnx+1][ry]=='O'){
                            if(rnx-1==bnx) continue; //빨강 통과 후 파랑이 뒤따라 들어가는 경우
                            cout << rcnt+1;
                            exit(0);
                        }
                        if(arr[bnx+1][by]!='O'){
                            R.push({rnx, ry, rcnt+1});
                            B.push({bnx, by, bcnt+1});
                            dir.push(i);
                        }
                    }
                }
                else{ //다른 열에 있을 경우
                    while(arr[bnx+1][by]!='#' && arr[bnx+1][by]!='O')
                        bnx++;
                    while(arr[rnx+1][ry]!='#' && arr[rnx+1][ry]!='O')
                        rnx++;
                    if(arr[rnx+1][ry]=='O'){
                        cout << rcnt+1;
                        exit(0);
                    }
                    if(arr[bnx+1][by]!='O'){
                        R.push({rnx, ry, rcnt+1});
                        B.push({bnx, by, bcnt+1});
                        dir.push(i);
                    }
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            arr[i][j]=s[j];
            if(s[j]=='R')
                Red={i, j};
            if(s[j]=='B')
                Blue={i, j};
        }
    }
    solve();
}