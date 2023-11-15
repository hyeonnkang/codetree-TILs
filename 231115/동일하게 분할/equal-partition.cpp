#include <bits/stdc++.h>
using namespace std;

#define MX 100
#define SUM_MAX 100000;

int n;
int num[MX+1];
int dp[MX+1];
int sum_all = 0; // 입력받은 숫자의 전체 합

int getSumOfAllNum(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += num[i];
    }
    return sum;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    sum_all = getSumOfAllNum();

    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = sum_all; j >= 0; j--){
            int x = num[i] + j;
            if(x <= sum_all && dp[j] > 0){
                dp[x] += dp[j];
            }
        }
    }

    cout << ( sum_all % 2 == 0 && (dp[(int)(sum_all/2)] > 0) ? "Yes" : "No");

    return 0;
}