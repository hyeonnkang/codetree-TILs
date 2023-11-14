#include <bits/stdc++.h>
using namespace std;

#define MX 100

int n, k;
int board[MX][MX];
int visited[MX][MX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isOutOfRange(int row, int col){
    return (row < 0 || row >= n || col < 0 || col >= n);
}

void dfs(int row, int col){
    for(int i = 0; i < 4; i++){
        int x = row + dx[i];
        int y = col + dy[i];

        if(isOutOfRange(x, y)) continue;

        if(visited[x][y] || board[x][y]) continue;

        visited[x][y] = 1;
        dfs(x, y);
    }
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < k; i++){
        int r, c;
        cin >> r >> c;

        visited[r-1][c-1] = 1;
        dfs(r-1, c-1);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j]) cnt++;
        }
    }
    cout << cnt;

    return 0;
}