#include <bits/stdc++.h>
using namespace std;

#define MX 100

int n;
int mat[MX+1][MX+1];
int dp[MX+1][MX+1];

void setFirstRow(){
    for(int j = 2; j <= n; j++){
        dp[1][j] = max(dp[1][j-1], mat[1][j]);
    }
}

void setFirstCol(){
    for(int i = 2; i <= n; i++){
        dp[i][1] = max(dp[i-1][1], mat[i][1]);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        fill(dp[i]+1, dp[i]+n, INT_MAX);
    }

    dp[1][1] = mat[1][1];
    setFirstRow();
    setFirstCol();

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            dp[i][j] = min(max(dp[i-1][j], mat[i][j]), max(dp[i][j-1], mat[i][j]));
        }
    }

    cout << dp[n][n];


    return 0;
}