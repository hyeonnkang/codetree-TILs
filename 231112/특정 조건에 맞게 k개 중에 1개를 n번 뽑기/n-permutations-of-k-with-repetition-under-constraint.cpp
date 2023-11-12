#include <bits/stdc++.h>
using namespace std;

#define MAX_K 4
#define MAX_N 8

int k, n;
int selected_num[MAX_N]; // 고른 숫자 리스트

void printSelectedNum(){
    for(int i = 0; i < n; i++){
        cout << selected_num[i] << " ";
    }cout << "\n";
}

// pre: 이전에 고른 숫자  cnt: 이전 숫자가 연속된 횟수  idx: 현재 고르는 숫자가 위치할 인덱스
void selectNum(int pre, int cnt, int idx){
    if(idx == n){ // 숫자를 모두 고른 경우
        printSelectedNum();
        return;
    }

    for(int num = 1; num <= k; num++){
        if(num == pre){
            if(cnt >= 2) continue;
            selected_num[idx] = num;
            selectNum(num, cnt+1, idx+1);
        }else{
            selected_num[idx] = num;
            selectNum(num, 1, idx+1);
        }
    }
}

int main() {
    cin >> k >> n;
    selectNum(0, 0, 0);

    return 0;
}