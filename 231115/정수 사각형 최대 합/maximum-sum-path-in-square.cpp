#include <bits/stdc++.h>
using namespace std;

#define MX 100

int n;
int mat[MX+1][MX+1];
int dp[MX+1][MX+1];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + mat[i][j];
        }
    }

    cout << dp[n][n];

    return 0;
}