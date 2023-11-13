#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MAX_N 10

int n;
int jump_distance[MAX_N];
int ans = INF;

void getInput();
void doJump(int pos, int jump_cnt);

int main() {
    getInput();

    doJump(0, 0);

    cout << ((ans == INF)? -1 : ans);

    return 0;
}

void doJump(int pos, int jump_cnt){
    if(pos >= n-1){
        ans = min(ans, jump_cnt);
        return;
    }

    for(int i = 1; i <= jump_distance[pos]; i++){
        doJump(pos+i, jump_cnt+1);
    }
}

void getInput(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> jump_distance[i];
    }
}