#include <bits/stdc++.h>
using namespace std;

#define MX 100
#define X first
#define Y second

int n, h, m;
int board[MX+1][MX+1];
int visited[MX+1][MX+1];
int dist[MX+1][MX+1];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int row, int col){
    for(int i = 1; i <= n; i++) fill(visited[i], visited[i]+n+1, 0);

    queue<pair<pair<int, int>, int>> Q;
    Q.push({{row, col}, 0});
    visited[row][col] = 1;

    int min_weight = -1;
    while(!Q.empty()){
        pair<int, int> cur = Q.front().first;
        int weight = Q.front().second;
        Q.pop();

        if(board[cur.X][cur.Y] == 3){
            if(min_weight == -1) min_weight = weight;
            else min_weight = min(min_weight, weight);
        }

        for(int i = 0; i < 4; i++){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 1 || x > n || y < 1 || y > n) continue;

            if(visited[x][y] || board[x][y] == 1) continue;

            visited[x][y] = 1;
            Q.push({{x, y}, weight+1});
        }
    }
    dist[row][col] = min_weight;
}

int main() {
    cin >> n >> h >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // 사람이라면, 비를 피할 수 있는 공간을 찾는다.
            if(board[i][j] == 2) bfs(i, j);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dist[i][j] << " ";
        }cout << "\n";
    }

    return 0;
}