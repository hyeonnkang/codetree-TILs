#include <bits/stdc++.h>
using namespace std;

#define MX 500

int n;
int mat[MX+1][MX+1];
int dp[MX+1][MX+1];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isOutOfRange(int r, int c){
    return (r < 1 || r > n || c < 1 || c > n);
}

void move(int r, int c){
    for(int i = 0; i < 4; i++){
        int next_r = r + dx[i];
        int next_c = c + dy[i];

        if(isOutOfRange(next_r, next_c)) continue;

        if(mat[next_r][next_c] <= mat[r][c]) continue;

        if(dp[r][c] + 1 > dp[next_r][next_c]){
            dp[next_r][next_c] = dp[r][c] + 1;
            move(next_r, next_c);
        }
        
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
        fill(dp[i]+1, dp[i]+n+1, 1);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            move(i, j);
        }  
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;

    return 0;
}