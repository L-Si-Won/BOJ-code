#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, zero, answer;
vector<int> a;
queue<int> robot; //로봇 위치
vector<bool> visit; //로봇이 있는지 여부

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    for(int i=0; i<2*n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
        visit.push_back(false);

        if(temp==0) zero++;
    }

    int up=0, down=n-1; //올리고, 내리는 위치
    while(1){
        answer++;

        //벨트 회전
        up--;
        down--;
        if(up<0) up=2*n-1;
        if(down<0) down=2*n-1;

        //로봇 이동
        int size=robot.size();
        for(int i=0; i<size; i++){
            int cur=robot.front();
            int next=(cur+1)%(2*n);
            robot.pop();
            visit[cur]=false;

            //내리는 위치 검사
            if(cur==down) continue;

            //다음 칸으로 이동 가능
            if(a[next]>=1 && visit[next]==false){
                a[next]--;
                visit[next]=true;

                if(a[next]==0) zero++;

                //내리는 위치 검사
                if(next==down) visit[next]=false;
                else robot.push(next);
            }
            //이동 불가능
            else{
                visit[cur]=true;
                robot.push(cur);
            }
        }

        //로봇 올리기
        if(visit[up]==false && a[up]>=1){
            robot.push(up);
            a[up]--;
            visit[up]=true;

            if(a[up]==0) zero++;
        }

        //종료
        if(zero>=k) break;
    }

    cout << answer;
}
