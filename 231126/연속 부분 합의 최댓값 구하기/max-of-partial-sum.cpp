#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MX_N 100000

int n;
int num[MX_N+1];
int dp[MX_N+1];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    fill(dp, dp+n+1, -INF);
    dp[1] = num[1];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i-1] + num[i], num[i]);
    }

    int ans = -INF;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}