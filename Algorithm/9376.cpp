#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, h, w;
char arr[102][102];
int min_door[3][102][102];
pair<int, int> crime[3];
bool visit[3][102][102];
int dx[]={1, 0, -1, 0};
int dy[]={0, 1, 0, -1};

void calculate_door(int idx){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    int x=crime[idx].first;
    int y=crime[idx].second;
    q.push({0, {x, y}});
    visit[idx][x][y]=true;
    min_door[idx][x][y]=0;

    while(!q.empty()){
        int cnt=q.top().first;
        int cx=q.top().second.first;
        int cy=q.top().second.second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx=cx+dx[i];
            int ny=cy+dy[i];

            if(nx>=0 && ny>=0 && nx<=h+1 && ny<=w+1){
                if(arr[nx][ny]=='*') continue;

                int ncnt=cnt;
                if(arr[nx][ny]=='#') ncnt++;

                if(min_door[idx][nx][ny] > ncnt){
                    min_door[idx][nx][ny]=ncnt;
                    visit[idx][nx][ny]=true;
                    q.push({ncnt, {nx, ny}});
                }
            }
        }
    }
}

void init()
{
	cin >> h >> w;

	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			arr[i][j] = '.';
			min_door[0][i][j] = 987654321;
			min_door[1][i][j] = 987654321;
			min_door[2][i][j] = 987654321;
			visit[0][i][j] = false;
			visit[1][i][j] = false;
			visit[2][i][j] = false;
		}
	}

	crime[0] = { -1,-1 };
	crime[1] = { -1,-1 };
	crime[2] = { 0,0 };
}

void make()
{
	// 감옥 바깥 '.'으로 채우기
	for (int i = 0; i <= h + 1; i++) {
		arr[i][0] = '.';
		arr[i][w + 1] = '.';
	}
	for (int i = 0; i <= w + 1; i++) {
		arr[0][i] = '.';
		arr[h + 1][i] = '.';
	}
	
	// 감옥 만들기
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '$') {
				if (crime[0].first == -1)
					crime[0] = { i,j };
				else
					crime[1] = { i,j };
			}
		}
	}
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        init();
        make();
        
        for(int j=0; j<3; j++)
            calculate_door(j);

        int result=987654321;
        for(int j=0; j<=h+1; j++){
            for(int k=0; k<=w+1; k++){
                if(arr[j][k]=='*') continue;
                if(visit[0][j][k]==false || visit[1][j][k]==false || visit[2][j][k]==false)
                    continue;
                int sum=0;
                for(int l=0; l<3; l++)
                    sum+=min_door[l][j][k];
                if(arr[j][k]=='#') sum-=2;

                result=min(result, sum);
            }
        }

        cout << result << "\n";
    }
}
