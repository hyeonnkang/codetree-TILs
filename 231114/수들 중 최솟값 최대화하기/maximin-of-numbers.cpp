#include <bits/stdc++.h>
using namespace std;

#define MX 10

int n;
int board[MX][MX];
int is_selected[MX];
int selected_num[MX];
int ans = 0;

void getInput();
int getMinOfSelectedNum();
void selectArea(int row);

int main() {
    getInput();
    selectArea(0);
    cout << ans;
    return 0;
}

void selectArea(int row){
    if(row == n){
        ans = max(ans, getMinOfSelectedNum());
        return;
    }

    for(int col = 0; col < n; col++){
        if(is_selected[col]) continue;
        is_selected[col] = 1;
        selected_num[row] = board[row][col];
        selectArea(row+1);
        is_selected[col] = 0;
    }
}

int getMinOfSelectedNum(){
    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        res = min(res, selected_num[i]);
    }
    return res;
}

void getInput(){
    cin >> n;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
}