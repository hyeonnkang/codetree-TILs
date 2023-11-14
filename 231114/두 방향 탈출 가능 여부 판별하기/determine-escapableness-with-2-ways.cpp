#include <bits/stdc++.h>
using namespace std;

#define MX 100

int n, m;

int board[MX][MX];
int visited[MX][MX];
int dx[] = {1, 0};
int dy[] = {0, 1};
int ans = 0;

bool isOutOfRange(int row, int col){
    return (row < 0 || row >= n || col < 0 || col >= m);
}

void dfs(int row, int col){
    if(ans == 1) return;
    if(row == n-1 && col == m-1) {
        ans = 1;
        return;
    }
    for(int i = 0; i < 2; i++){
        int x = row + dx[i];
        int y = col + dy[i];

        if(isOutOfRange(x, y)) continue;

        if(visited[x][y] || !board[x][y]) continue;

        visited[x][y] = 1;
        dfs(x, y);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    visited[0][0] = 1;
    dfs(0, 0);

    cout << ans;

    return 0;
}