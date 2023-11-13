#include <bits/stdc++.h>
using namespace std;

#define MAX_N_M 10

int n, m;
int selected_num[MAX_N_M+1];

void selectNum(int cur, int pre){
    if(cur > m){
        for(int i = 1; i <= m; i++){
            cout << selected_num[i] << " ";
        }cout << "\n";
        return;
    }

    for(int i = pre; i <= n; i++){
        selected_num[cur] = i;
        selectNum(cur+1, i+1);
    }
}

int main() {
    cin >> n >> m;

    selectNum(1, 1);

    return 0;
}