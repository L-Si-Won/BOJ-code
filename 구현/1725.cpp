#include <iostream>

using namespace std;

int n, arr[100'000];

int dnc(int start, int end){
    //넓이를 구하지 못하는 경우
    if (start > end)
        return 0;
    //한 개의 막대 자체가 넓이
    if (start == end)
        return arr[start];
    
    int mid = (start + end) / 2;
    int base = 1;
    int altitude = arr[mid];
    int area = arr[mid];

    int left = mid - 1;
    int right = mid + 1;

    //양쪽 중 높이가 더 높은 곳으로 확장
    while (start <= left && right <= end){
        if (arr[left] > arr[right]){
            altitude = min(altitude, arr[left]);
            left--;
        }
        else{
            altitude = min(altitude, arr[right]);
            right++;
        }
        base++;
        area = max(area, base * altitude);
    }

    //왼쪽끝까지 확장
    while (start <= left){
        base++;
        altitude = min(altitude, arr[left]);
        area = max(area, base * altitude);
        left--;
    }

    //오른쪽끝까지 확장
    while (right <= end){
        base++;
        altitude = min(altitude, arr[right]);
        area = max(area, base * altitude);
        right++;
    }

    //범위 분할
    area = max(area, dnc(start, mid - 1));
    area = max(area, dnc(mid + 1, end));

    return area;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    //input
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    //devide and conquer and output
    cout << dnc(0, n - 1);
}
