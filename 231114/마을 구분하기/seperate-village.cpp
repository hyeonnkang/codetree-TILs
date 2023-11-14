#include <bits/stdc++.h>
using namespace std;

#define MX 25

int n;

int city[MX][MX];
int visited[MX][MX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt = 0; // 마을 내 사람의 수

vector<int> people;

bool isOutOfRange(int row, int col){
    return (row < 0 || row >= n || col < 0 || col >= n);
}

void dfs(int row, int col){
    cnt++;
    for(int i = 0; i < 4; i++){
        int x = row + dx[i];
        int y = col + dy[i];

        if(isOutOfRange(x, y)) continue;

        if(visited[x][y] || !city[x][y]) continue;

        visited[x][y] = 1;
        dfs(x, y);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> city[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && city[i][j]){
                cnt = 0;
                visited[i][j] = 1;
                dfs(i, j);
                people.push_back(cnt);
            }
        }
    }

    sort(people.begin(), people.end());

    cout << (int)people.size() << "\n";
    for(auto it = people.begin(); it != people.end(); it++){
        cout << *it << "\n";
    }

    return 0;
}