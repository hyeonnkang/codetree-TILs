#include <bits/stdc++.h>
using namespace std;

#define MX_N 1000

int n;
pair<int, int> pos[MX_N];
int cnt[4]; // 각 영역의 점의 갯수

int main() {
    // 입력받기
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> pos[i].first >> pos[i].second;
    }

    // 모두 더해서 x, y 평균값 구하기
    int avg_x = 0;
    int avg_y = 0;
    for(int i = 0; i < n; i++){
        avg_x += pos[i].first;
        avg_y += pos[i].second;
    }
    avg_x = avg_x / n;
    avg_y = avg_y / n;

    int ans = 0;
    for(int k = 0; k < 2; k++, avg_x++, avg_y++){
        // 각 영역 점의 갯수 구하기
        fill(cnt, cnt+4, 0);
        for(int i = 0; i < n; i++){
            if(pos[i].first < avg_x){
                if(pos[i].second < avg_y) cnt[3]++;
                else cnt[2]++;
            }else{
                if(pos[i].second < avg_y) cnt[4]++;
                else cnt[1]++;
            }
        }

        // 최대 점의 갯수 구하기
        int mx_cnt = 0;
        for(int i = 0; i < 4; i++){
            mx_cnt = max(mx_cnt, cnt[i]);
        }
        ans = max(ans, mx_cnt);
    }
    cout << ans;

    return 0;
}