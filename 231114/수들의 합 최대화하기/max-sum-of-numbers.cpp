#include <bits/stdc++.h>
using namespace std;

#define MX 10

int n;
int num[MX+1][MX+1];
int col_visited[MX+1];
int ans = 0; // n 개의 색칠된 칸의 합 중 최댓값
int chosen_num[MX+1];

void choose(int cur, int sum){
    if(cur > n){
        ans = max(ans, sum);
        return;
    }

    for(int i = 1; i <= n; i++){
        if(col_visited[i]) continue;
        col_visited[i] = 1;
        chosen_num[cur] = num[cur][i];
        choose(cur+1, sum + num[cur][i]);
        col_visited[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j= 1; j <= n; j++){
            cin >> num[i][j];
        }
    }

    choose(1, 0);

    cout << ans;

    return 0;
}