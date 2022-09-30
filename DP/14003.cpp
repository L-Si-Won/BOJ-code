#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, max_idx, max_dp;
int arr[1000000];
int dp[1000000];
vector<int> length;
vector<int> answer;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    length.push_back(arr[0]);
    dp[0]=1;
    for(int i=1; i<n; i++){
        //증가하는 부분 수열의 마지막 원소보다 크면
        //수열 가장 마지막에 추가
        if(*(length.end()-1)<arr[i]) {
            length.push_back(arr[i]);
            dp[i]=length.size(); 
        }

        //증가하는 부분 수열의 마지막 원소보다 작거나 같으면
        //증가하는 부분 수열의 원소 중 arr[i] 이상인 첫 번째 수와 교환
        else {
            //arr[i] 이상인 첫 번째 수를 가리키는 이터레이터
            vector<int>::iterator iter=lower_bound(length.begin(), length.end(), arr[i]);
            
            *(iter)=arr[i];
            dp[i]=iter-length.begin()+1; //이터레이터-begin=이터레이터의 인덱스 값
        }
        
        //증가하는 부분 수열 중 마지막 원소의 인덱스 구하기
        if(dp[i]>max_dp){
            max_dp=dp[i];
            max_idx=i;
        }
    }

    //answer 벡터에 수열의 가장 큰 수부터 저장
    answer.push_back(arr[max_idx]);
    for(int i=max_idx-1; i>=0; i--){
        if(arr[i]<arr[max_idx] && dp[i]==dp[max_idx]-1){
            max_idx=i;
            answer.push_back(arr[i]);
        }
    }
    
    //정답 출력
    cout << length.size() << "\n"; //수열 길이 출력
    for(int i=answer.size()-1; i>=0; i--)
        cout << answer[i] << " ";
}
