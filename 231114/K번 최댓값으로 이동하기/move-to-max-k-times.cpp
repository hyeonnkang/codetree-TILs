#include <bits/stdc++.h>
using namespace std;

#define MX 100

int n, k;
int board[MX+1][MX+1];
int visited[MX+1][MX+1];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int r, c; // dfs의 시작 좌표 위치
int cnt = 0; // dfs에서 새로 탐색한 좌표의 갯수

bool isOutOfRange(int row, int col){
    return (row < 1 || row > n || col < 1 || col > n);
}

void setPos(int row, int col){
    r = row;
    c = col;
}

void dfs(int num, int row, int col){
    for(int i = 0; i < 4; i++){
        int x = row + dx[i];
        int y = col + dy[i];

        if(isOutOfRange(x, y)) continue;

        if(visited[x][y] || board[x][y] >= num) continue;

        if(cnt == 0 || board[x][y] > board[r][c]){
            setPos(x, y);
        }else if(board[x][y] == board[r][c]){
            if(x < r) setPos(x, y);
            else if(x == r && y < c) setPos(x, y);
        }

        cnt++;
        visited[x][y] = 1;
        dfs(num, x, y);
    }
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> board[i][j];
        }
    }

    cin >> r >> c;

    for(int repeat = 0; repeat < k; repeat++){
        // 초기화
        for(int i = 1; i <= n; i++) fill(visited[i], visited[i]+n+1, 0);
        cnt = 0;

        // 탐색 시작
        visited[r][c] = 1;
        dfs(board[r][c], r, c);

        if(cnt == 0) break;
    }
    

    cout << r << " " << c;

    return 0;
}