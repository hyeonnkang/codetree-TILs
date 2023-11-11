#include <bits/stdc++.h>
using namespace std;

#define MX 20

int n, m;
int arr[MX][MX];
int visited[MX][MX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans = 0; // 가장 많은 금의 개수

bool isNotValidRange(int row, int col){
    return (row < 0 || row >= n || col < 0 || col >= n);
}

void bfs(int i, int j, int k){
    // visited 초기화
    for(int i = 0; i < n; i++) fill(visited[i], visited[i]+n, 0);
    
    // (현재 좌표, 현재 이동할 수 있는 횟수)
    queue<pair<pair<int, int>, int>> Q;
    // 시작점 넣기
    Q.push({{i, j}, k});
    visited[i][j] = 1;

    int gold_cnt = 0; // 탐색한 영역 내의 금의 갯수
    if(arr[i][j]) gold_cnt++;

    // bfs 탐색
    while(!Q.empty()){
        pair<pair<int, int>, int> cur = Q.front(); Q.pop();
        pair<int, int> cur_pos = cur.first; // 현재 좌표
        int cur_cnt = cur.second; // 현재 이동할 수 있는 횟수

        if(cur_cnt == 0) continue; // 이동할 수 있는 횟수가 없으면 건너뛰기

        for(int i = 0; i < 4; i++){
            int next_x = cur_pos.first + dx[i];
            int next_y = cur_pos.second + dy[i];

            // 범위를 벗어났으면 건너뛰기
            if(isNotValidRange(next_x,next_y)) continue;

            // 이미 방문한 곳이면 건너뛰기
            if(visited[next_x][next_y]) continue;

            // 큐에 넣기
            visited[next_x][next_y] = 1;
            Q.push({{next_x, next_y}, cur_cnt-1});
            if(arr[next_x][next_y]) gold_cnt++;
        }
    }

    // 금의 가격과 채굴에 드는 비용을 비교해서 ans 업데이트
    int gold_price = gold_cnt * m;
    int traversal_price = k*k + (k+1)*(k+1);
    if(gold_price >= traversal_price) {
        ans = max(ans, gold_cnt);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k <= n; k++){
                bfs(i, j, k);
            }
        }
    }

    cout << ans;

    return 0;
}