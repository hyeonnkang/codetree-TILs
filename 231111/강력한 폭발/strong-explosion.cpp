#include <bits/stdc++.h>

using namespace std;

#define MX 20

int n;
int dx[][5] = {
        {-2, -1, 0, 1,  2}, // 1번 폭탄
        {0,  0,  0, -1, 1}, // 2번 폭탄
        {-1, -1, 0, 1,  1} // 3번 폭탄
};
int dy[][5] = {
        {0,  0, 0, 0,  0}, // 1번 폭탄
        {-1, 0, 1, 0,  0}, // 2번 폭탄
        {-1, 1, 0, -1, 1} // 3번 폭탄
};
int board[MX][MX];
int visited[MX][MX]; // 폭발 지역일 경우 1, 아닐 경우 0
vector<pair<int, int>> boom_pos; // 폭발좌표 리스트
int ans = 0; // 가장 많이 폭발하는 영역의 수

void getInput(); // 사용자의 입력을 받는다
void setBoomPos(); // 폭발 좌표를 저장한다
void doBoom(int cur); // 폭발 수행 (cur = 폭발좌표 인덱스)

int main() {
    getInput();
    setBoomPos();
    doBoom(0);
    cout << ans;
    return 0;
}

void doBoom(int cur) {
    if (cur == boom_pos.size()) {
        // 폭발한 지역 갯수 세기
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] || board[i][j]) cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }

    visited[boom_pos[cur].first][boom_pos[cur].second] = 1;
    for (int boom = 0; boom < 3; boom++) {
        // 현재 폭발로 인해 새로 추가된 폭발 지역
        vector<pair<int, int>> visit_list;
        for (int i = 0; i < 5; i++) {
            int x = boom_pos[cur].first + dx[boom][i];
            int y = boom_pos[cur].second + dy[boom][i];

            // 좌표 범위가 올바른지 확인
            if (x < 0 || x >= n || y < 0 || y >= n) continue;

            // 이미 방문한 곳인지 확인
            if (visited[x][y]) continue;

            visited[x][y] = 1;
            visit_list.push_back({x, y});
        }
        doBoom(cur + 1);
        // visit_list 롤백
        for(int i = 0; i < (int)visit_list.size(); i++){
            pair<int, int> cur = visit_list[i];
            visited[cur.first][cur.second] = 0;
        }
        visit_list.clear();
    }
}

void setBoomPos() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                boom_pos.push_back({i, j});
            }
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
}