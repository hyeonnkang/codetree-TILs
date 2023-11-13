#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MX 10

int n;
int cost[MX+1][MX+1];
int visited[MX+1];
int ans = INF;

// cur: 현재 위치  weight: 누적 비용  cnt: 누적 방문 지점 갯수
void move(int cur, int weight, int cnt){
    if(cnt == n){
        if(cost[cur][1] != 0)
            ans = min(ans, weight + cost[cur][1]);
        return;
    }
    for(int i = 2; i <= n; i++){
        // 이동할 수 없거나 방문했으면 패스
        if(cost[cur][i] == 0 || visited[i]) continue;

        visited[i] = 1;
        move(i, weight + cost[cur][i], cnt+1);
        visited[i] = 0;
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> cost[i][j];
        }
    }

    visited[1] = 1;
    move(1, 0, 1);
    cout << ans;

    return 0;
}