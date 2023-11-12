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
void move(int dir, int row, int col, int cnt, int pre_num); // (row, col)에서 dir 방향으로 이동하며 ans를 업데이트한다

int main() {
    getInput();

    move(direction[r - 1][c - 1], r - 1, c - 1, 0, board[r - 1][c - 1]);

    cout << ans;

    return 0;
}

void move(int dir, int row, int col, int cnt, int pre_num) {
    int next_row = row;
    int next_col = col;
    for (int i = 0; i < 4; i++) {
        next_row += dx[dir];
        next_col += dy[dir];

        if (isOutOfRange(next_row, next_col)) { // 격자 범위를 벗어난 경우
            ans = max(ans, cnt);
            break;
        } else if (board[next_row][next_col] <= pre_num) { // 이전 숫자보다 크지 않은 경우 건너뛰기
            continue;
        } else {
            move(dir, next_row, next_col, cnt, pre_num); // 방향 그대로
            move(direction[next_row][next_col], next_row, next_col, cnt + 1, board[next_row][next_col]); // 방향 전환
        }
    }
}

void getInput() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> direction[i][j];
        }
    }

    cin >> r >> c;
}

bool isOutOfRange(int row, int col) {
    return (row < 0 || row >= n || col < 0 || col >= n);
}