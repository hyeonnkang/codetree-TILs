#include <bits/stdc++.h>
using namespace std;

#define MAX_N 12
#define MAX_M 100
#define MAX_K 4

int n, m, k;
int pos[MAX_K+1]; // pos[i] : i번 숫자가 위치한 숫자번호
int moving[MAX_N]; // 각 라운드마다 나아갈 수 있는 거리
int ans = 0; // 최대로 얻을 수 있는 점수

// 사용자의 입력을 받는다.
void getInput();
// 숫자 m에 도달한 말의 갯수를 세어 점수를 return
int getScore();
// 각 라운드를 플레이하며 말을 움직인다
void playRound(int round); // round: 현재 플레이중인 라운드

int main() {
    getInput();
    fill(pos, pos+k+1, 1);
    playRound(0);
    cout << ans;
    return 0;
}

void getInput(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> moving[i];
    }
}

int getScore(){
    int score = 0;
    for(int i = 1; i <= k; i++){
        if(pos[i] >= m) score++;
    }
    return score;
}

void playRound(int round){
    if(round >= n){ // 라운드가 모두 종료되었을 때
        ans = max(ans, getScore());
        return;
    }
    
    for(int i = 1; i <= k; i++){
        pos[i] += moving[round];
        playRound(round+1);
        pos[i] -= moving[round];
    }
}