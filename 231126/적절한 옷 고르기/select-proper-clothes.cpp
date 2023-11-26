#include <bits/stdc++.h>
using namespace std;

#define MX 200

int n, m;
tuple<int, int, int> clothes[MX+1];
int dp[MX+1][MX+1];


int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int s, e, v;
        cin >> s >> e >> v;
        clothes[i] = {s, e, v};
    }

    for(int i = 1; i < m; i++){
        for(int j = 1; j <= n; j++){
            if(i < get<0>(clothes[j]) || i > get<1>(clothes[j])) continue;
            for(int k = 1; k <= n; k++){
                if(i+1 < get<0>(clothes[k]) || i+1 > get<1>(clothes[k])) continue;

                dp[i+1][k] = max(dp[i+1][k], dp[i][j] + abs(get<2>(clothes[j])-get<2>(clothes[k])));
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[m][i]);
    }
    cout << ans;

    return 0;
}