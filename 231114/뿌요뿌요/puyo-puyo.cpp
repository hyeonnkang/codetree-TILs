#include <bits/stdc++.h>
using namespace std;

#define MX 100

int n;
int block[MX][MX];
int visited[MX][MX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt = 0;

bool isOutOfRange(int row, int col){
    return (row < 0 || row >= n || col < 0 || col >= n);
}

void dfs(int num, int row, int col){
    cnt++;
    for(int i = 0; i < 4; i++){
        int x = row + dx[i];
        int y = col + dy[i];

        if(isOutOfRange(x, y)) continue;

        if(visited[x][y] || block[x][y] != num) continue;

        visited[x][y] = 1;
        dfs(num, x, y);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> block[i][j];
        }
    }

    int boom_block_cnt = 0; // 터지는 블럭 수
    int max_block_sz = 0; // 최대 블럭의 크기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                cnt = 0;
                visited[i][j] = 1;
                dfs(block[i][j], i, j);
                if(cnt >= 4) boom_block_cnt++;
                max_block_sz = max(max_block_sz, cnt);
            }
        }
    }

    cout << boom_block_cnt << " " << max_block_sz;

    return 0;
}