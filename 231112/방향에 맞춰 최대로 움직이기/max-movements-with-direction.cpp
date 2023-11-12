#include <bits/stdc++.h>
using namespace std;

#define MAX_N 4

int n;
int r, c;
int board[MAX_N][MAX_N];
int direction[MAX_N][MAX_N];
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int ans = 0; // 이동할 수 있는 최대 횟수

void getInput(); // 사용자로부터 입력을 받는다
bool isOutOfRange(int row, int col); // 격자 범위를 벗어난 경우 true return
void move(int dir, int row, int col, int cnt); // (row, col)에서 dir 방향으로 이동하며 ans를 업데이트한다

int main() {
    getInput();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            move(direction[i][j], i, j, 0);
        }
    }

    cout << ans;

    return 0;
}

void move(int dir, int row, int col, int cnt){
    int next_row = row;
    int next_col = col;
    for(int i = 0; i < 4; i++){
        next_row += dx[dir];
        next_col += dy[dir];


        // 격자 범위를 벗어나거나 현재 숫자보다 크지 않은 경우
        if(isOutOfRange(next_row, next_col)){
            ans = max(ans, cnt);
            break;
        }else if(board[next_row][next_col] <= board[row][col]){
            continue;
        }else{
            move(dir, next_row, next_col, cnt);
            move(direction[next_row][next_col], next_row, next_col, cnt+1);
        }
    }
}

void getInput(){
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j= 0; j < n; j++){
            cin >> direction[i][j];
        }
    }

    cin >> r >> c;
}

bool isOutOfRange(int row, int col){
    return (row < 0 || row >= n || col < 0 || col >= n);
}