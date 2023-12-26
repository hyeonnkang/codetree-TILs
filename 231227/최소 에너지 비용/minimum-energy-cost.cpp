#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MX_N 100000

int n;
int move_cost[MX_N];
int charge_cost[MX_N];
int min_charge_cost[MX_N]; // min_charge_cost[i] : 0~i까지 중 가장 작은 에너지 충전 비용

int main() {
    // 입력받기
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> move_cost[i];
    }
    for(int i = 0; i < n; i++){
        cin >> charge_cost[i];
    }

    // 각 위치에서 최소 충전 비용 구하기
    min_charge_cost[0] = charge_cost[0];
    for(int i = 1; i < n; i++){
        min_charge_cost[i] = min(charge_cost[i], min_charge_cost[i-1]);
    }

    // 필요한 충전 총량 구하기
    ll sum = 0;
    for(int i = 0; i < n-1; i++){
        sum += (ll)move_cost[i] * (ll)min_charge_cost[i];
    }  
    cout << sum;

    return 0;
}