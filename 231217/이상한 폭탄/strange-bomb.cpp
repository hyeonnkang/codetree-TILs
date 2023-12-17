#include <bits/stdc++.h>
using namespace std;

#define MX_N 200000

int n, k;
int boom[MX_N+1];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> boom[i];
    }

    int ans = -1; // 터지는 폭탄 중 가장 큰 번호
    unordered_map<int, int> last_pos; // {폭탄 번호, 이전에 발견된 마지막 위치}
    for(int i = 1; i <= n; i++){
        int cur = boom[i]; // 현재 폭탄 번호
        if(last_pos.find(cur) == last_pos.end()){ // 처음 나온 폭탄 번호일경우
            last_pos[cur] = i;
        }else{
            // 터질 경우, ans 업데이트
            if(i - last_pos[cur] <= k){
                ans = max(ans, cur);
            }

            // 폭탄의 마지막 위치를 현재 인덱스로 설정
            last_pos[cur] = i;
        }
    }
    cout << ans;

    return 0;
}