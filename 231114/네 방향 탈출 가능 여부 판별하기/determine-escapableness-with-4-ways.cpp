#include <bits/stdc++.h>
using namespace std;

#define MX 100

int n, m;
int board[MX][MX];
int visited[MX][MX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isOutOfRange(int row, int col){
    return (row < 0 || row >= n || col < 0 || col >= m);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> Q;
    visited[0][0] = 1;
    Q.push({0, 0}); 
    int ans = 0;
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        
        if(cur.first == n-1 && cur.second == m-1){
            ans = 1;
            break;
        }

        for(int i = 0; i < 4; i++){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];

            if(isOutOfRange(x, y)) continue;

            if(visited[x][y] || !board[x][y]) continue;

            visited[x][y] = 1;
            Q.push({x, y});
        }
    }
    cout << ans;

    return 0;
}