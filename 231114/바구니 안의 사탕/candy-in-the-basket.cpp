#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100000
#define MAX_POS 1000000

int n, k;
pair<int, int> candy[MAX_N+1]; // 사탕 갯수, 바구니 좌표
int candy_cnt[MAX_POS+1];
int candy_sum[MAX_POS+1];

int main() {
    cin >> n >> k;

    int pos_max = 0;
    for(int i = 1; i <= n; i++){
        cin >> candy[i].first >> candy[i].second;
        candy_cnt[candy[i].second] = candy[i].first;
        pos_max = max(pos_max, candy[i].second);
    }

    for(int i = 1; i <= pos_max; i++){
        candy_sum[i] += candy_sum[i-1] + candy_cnt[i];
    }

    int ans = 0; // 구간 내의 사탕의 최대 갯수
    int mid = k + 1;
    for(; mid + k <= pos_max; mid++){
        ans = max(ans, candy_sum[mid+k] - candy_sum[mid-k] + candy_cnt[mid-k]);
    }
    cout << ans;

    return 0;
}