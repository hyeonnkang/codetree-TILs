#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MAX_N 10

int n;
int num[MAX_N];
int is_selected[MAX_N];
int sum_all = 0; // num의 모든 숫자의 합
int ans = INF; // 두 그룹의 원소합의 차

void getInput(); // 입력받기
void calSumOfAllNum(); // num의 모든 숫자의 합 구하기
int calculateDiff(); // 두 그룹 간의 원소 합의 차 반환
void selectNum(int cur, int cnt); // 숫자를 선택

int main() {
    getInput();
    calSumOfAllNum();
    selectNum(0, 0);
    cout << ans;
    return 0;
}

void getInput(){
    cin >> n;
    for(int i = 0; i < 2*n; i++){
        cin >> num[i];
    }
}

void calSumOfAllNum(){
    int sum = 0;
    for(int i = 0; i < 2*n; i++)
        sum += num[i];
    sum_all = sum;
}

int calculateDiff(){
    int sum = 0;
    for(int i = 0; i < 2*n; i++){
        if(is_selected[i]){
            sum += num[i];
        }
    }
    return abs(sum - (sum_all - sum));
}

void selectNum(int cur, int cnt){
    if(cnt == n){
        ans = min(ans, calculateDiff());
        return;
    }
    if(cur == 2*n || n-cnt > 2*n-cur+1 || cnt > n) return;

    // 숫자를 선택하지 X
    selectNum(cur+1, cnt);

    // 숫자를 선택
    is_selected[cur] = 1;
    selectNum(cur+1, cnt+1);
    is_selected[cur] = 0;
}