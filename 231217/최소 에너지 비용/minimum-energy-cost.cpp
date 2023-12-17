#include <bits/stdc++.h>
using namespace std;

#define MX_N 100000

int n;
int move_cost[MX_N];
int charge_cost[MX_N];
int min_charge_cost[MX_N]; // min_charge_cost[i] : 0~i까지 중 가장 작은 에너지 충전 비용

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> move_cost[i];
    }
    for(int i = 0; i < n; i++){
        cin >> charge_cost[i];
    }

    min_charge_cost[0] = charge_cost[0];
    for(int i = 1; i < n; i++){
        min_charge_cost[i] = min(charge_cost[i], min_charge_cost[i-1]);
    }

    int sum = 0;
    for(int i = 0; i < n-1; i++){
        sum += move_cost[i] * min_charge_cost[i];
    }  
    cout << sum;

    return 0;
}