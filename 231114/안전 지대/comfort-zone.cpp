#include <bits/stdc++.h>
using namespace std;

#define MX 50

int n, m;
int town[MX][MX];
int visited[MX][MX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool isOutOfRange(int row, int col){
    return (row < 0 || row >= n || col < 0 || col >= m);
}

void dfs(int row, int col, int k){
    for(int i = 0; i < 4; i++){
        int x = row + dx[i];
        int y = col + dy[i];

        if(isOutOfRange(x, y)) continue;

        if(visited[x][y] || town[x][y] <= k) continue;

        visited[x][y] = 1;
        dfs(x, y, k);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> town[i][j];
        }
    }

    int max_cnt = 0;
    int max_k = 1;
    for(int k = 1; k <= 100; k++){
        // visited 초기화
        for(int i = 0; i < n; i++) fill(visited[i], visited[i] + m, 0);

        int cnt = 0; // 안전 영역의 수

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && town[i][j] > k){
                    cnt++;
                    visited[i][j] = 1;
                    dfs(i, j, k);
                }
            }
        }
        if(cnt > max_cnt){
            max_cnt = cnt;
            max_k = k;
        }
    }
    cout << max_k << " " << max_cnt;

    return 0;
}