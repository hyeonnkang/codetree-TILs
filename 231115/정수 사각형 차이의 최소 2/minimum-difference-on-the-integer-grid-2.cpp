#include <bits/stdc++.h>
using namespace std;

#define MX 100

int n;
int mat[MX+1][MX+1];
tuple<int, int, int> dp[MX+1][MX+1]; // |최댓값-최솟값|, 최댓값, 최솟값

void setFirstRow(){
    for(int j = 2; j <= n; j++){
        int mx = max(get<1>(dp[1][j-1]), mat[1][j]);
        int mn = min(get<2>(dp[1][j-1]), mat[1][j]);

        if(abs(mx-mn) < get<0>(dp[1][j])){
            dp[1][j] = {abs(mx-mn), mx, mn};
        }
    }
}

void setFirstCol(){
    for(int i = 2; i <= n; i++){
        int mx = max(get<1>(dp[i-1][1]), mat[i][1]);
        int mn = min(get<2>(dp[i-1][1]), mat[i][1]);

        if(abs(mx-mn) < get<0>(dp[i][1])){
            dp[i][1] = {abs(mx-mn), mx, mn};
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1;  j <= n; j++){
            cin >> mat[i][j];
        }
    }

    // dp 초기화
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = {INT_MAX, INT_MIN, INT_MAX};
        }
    }

    // 시작점 설정
    dp[1][1] = {0, mat[1][1], mat[1][1]};
    setFirstRow();
    setFirstCol();

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            int mx_up = max(get<1>(dp[i-1][j]), mat[i][j]);
            int mn_up = min(get<2>(dp[i-1][j]), mat[i][j]);

            int mx_left = max(get<1>(dp[i][j-1]), mat[i][j]);
            int mn_left = min(get<2>(dp[i][j-1]), mat[i][j]);

            if(abs(mx_up - mn_up) < abs(mx_left - mn_left)){
                dp[i][j] = {abs(mx_up - mn_up), mx_up, mn_up};
            }else if (abs(mx_up - mn_up) > abs(mx_left - mn_left)){
                dp[i][j] = {abs(mx_left - mn_left), mx_left, mn_left};
            }else{
                if(mx_up < mx_left) dp[i][j] = {abs(mx_up - mn_up), mx_up, mn_up};
                else dp[i][j] = {abs(mx_left - mn_left), mx_left, mn_left};
            }
        }
    }

    cout << get<0>(dp[n][n]);

    return 0;
}