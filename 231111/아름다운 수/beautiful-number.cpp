#include <bits/stdc++.h>
using namespace std;

#define MX 10

int n;
int chosen_num[MX]; // 고른 숫자
int ans = 0; // 아름다운 수의 갯수

int count_num[5];

// 현재 고른 숫자 리스트가 아름다운 숫자이면 true return
bool isPrettyNum(){
    fill(count_num, count_num+5, 0);

    for(int i = 0; i < n; i++){
        count_num[chosen_num[i]]++;
    }

    bool res = true;
    for(int i = 1; i <= 4; i++){
        if(count_num[i] % i != 0) res = false;
    }
    return res;
}

// 숫자를 차례로 고르는 함수
// idx : 숫자 리스트의 인덱스 num : 최근에 넣은 숫자 k : num을 고른 횟수
void choose(int idx, int num, int k){
    if(idx == n){
        // 아름다운 숫자일 경우 카운트
        if(isPrettyNum()) ans++;
        return;
    }

    if(num == k){
        for(int i = 1; i <= 4; i++){
            chosen_num[idx] = i;
            choose(idx+1, i, 1);
        }
    }else{
        chosen_num[idx] = num;
        choose(idx+1, num, k+1);
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= 4; i++){
        choose(0, i, 0);
    }

    cout << ans;

    return 0;
}