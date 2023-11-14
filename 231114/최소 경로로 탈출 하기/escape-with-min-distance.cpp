#include <bits/stdc++.h>
using namespace std;

#define ROW first
#define COL second

int n, m;
int mat[100][100];
int visited[100][100];
int drow[] = {1, 0, -1, 0};
int dcol[] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    
    queue<pair<pair<int, int>, int>> Q;
    visited[0][0] = 1;
    Q.push({{0, 0}, 0});

    int res = -1;
    while(!Q.empty()){
        pair<pair<int, int>, int> tmp = Q.front(); Q.pop();
        int curRow = tmp.first.ROW;
        int curCol = tmp.first.COL;
        int weight = tmp.second;

        if(curRow == n-1 && curCol == m-1){
            res = res == -1 ? weight : min(res, weight);
            break;
        }

        for(int i = 0; i < 4; i++){
            int row = curRow + drow[i];
            int col = curCol + dcol[i];

            if(row < 0 || row >= n || col < 0 || col >= m) continue;

            if(visited[row][col] || !mat[row][col]) continue;

            visited[row][col] = 1;
            Q.push({{row, col}, weight+1});
        }
    }

    cout << res;

    return 0;
}