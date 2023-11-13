#include <bits/stdc++.h>
using namespace std;

#define MAX_N_M 20

int n, m;
int num[MAX_N_M];
int selected_num[MAX_N_M];
int ans = 0; // xor 결과의 최댓값

void getInput();
int calculateXOR();
void selectNum(int cur, int pre);

int main() {
    getInput();
    selectNum(0, 0);
    cout << ans;

    return 0;
}

int calculateXOR(){
    int res = 0;
    for(int i = 0; i < m; i++){
        res ^= selected_num[i];
    }
    return res;
}

void selectNum(int cur, int pre){
    if(cur == m){
        ans = max(ans, calculateXOR());
        return;
    }

    for(int i = pre; i < n; i++){
        selected_num[cur] = num[i];
        selectNum(cur+1, i+1);
    }
}

void getInput(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
}