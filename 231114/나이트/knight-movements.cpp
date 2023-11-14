#include <bits/stdc++.h>
using namespace std;

#define MX 100
#define X first
#define Y second

int n;
int r1, c1; // 시작 위치
int r2, c2; // 도착 위치
int board[MX+1][MX+1];
int visited[MX+1][MX+1];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<pair<pair<int, int>, int>> Q;
    visited[r1][c1] = 1;
    Q.push({{r1, c1}, 0});
    int ans = -1;
    while(!Q.empty()){
        pair<int, int> cur = Q.front().first; 
        int weight = Q.front().second;
        Q.pop();

        if(cur.X == r2 && cur.Y == c2){
            if(ans == -1) ans = weight;
            else ans = min(ans, weight);
        }

        for(int i = 0; i < 8; i++){
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];

            if(x < 1 || x > n || y < 1 || y > n) continue;

            if(visited[x][y]) continue;

            visited[x][y] = 1;
            Q.push({{x, y}, weight+1});
        }
    }
    cout << ans;

    return 0;
}