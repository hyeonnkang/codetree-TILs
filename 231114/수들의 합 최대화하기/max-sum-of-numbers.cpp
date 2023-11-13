#include <bits/stdc++.h>
using namespace std;

#define MX 10

int n;
int num[MX+1][MX+1];
int row_visited[MX+1];
int col_visited[MX+1];
int ans = 0; // n 개의 색칠된 칸의 합 중 최댓값
int chosen_num[MX+1];

int calculateSum(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += chosen_num[i];
    }
    return sum;
}

void choose(int cur){
    if(cur > n){
        ans = max(ans, calculateSum());
        return;
    }

    for(int i = 1; i <= n; i++){
        if(row_visited[i]) continue;
        for(int j = 1; j <= n; j++){
            if(col_visited[j]) continue;

            row_visited[i] = 1;
            col_visited[j] = 1;
            chosen_num[cur] = num[i][j];
            choose(cur+1);
            row_visited[i] = 0;
            col_visited[j] = 0;
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j= 1; j <= n; j++){
            cin >> num[i][j];
        }
    }

    choose(1);

    cout << ans;

    return 0;
}