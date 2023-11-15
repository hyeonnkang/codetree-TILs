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

    // 맨 첫번째 행 계산
    dp[1][n] = mat[1][n];
    for(int j = n-1; j >= 1; j--){
        dp[1][j] = dp[1][j+1] + mat[1][j];
    }

    // 2~n 번째 행 계산
    for(int i = 2; i <= n; i++){
        for(int j = n; j >= 1; j--){
            if(j == n)
                dp[i][j] = dp[i-1][j] + mat[i][j];
            else 
                dp[i][j] = min(dp[i][j+1], dp[i-1][j]) + mat[i][j];
        }
    }
    
    cout << dp[n][1];

    return 0;
}