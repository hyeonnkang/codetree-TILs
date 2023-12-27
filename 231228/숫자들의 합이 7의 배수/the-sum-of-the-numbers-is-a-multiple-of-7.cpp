#include <bits/stdc++.h>
using namespace std;

#define MX_N 50000

int n;
int num[MX_N];
int sum[MX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    sum[0] = num[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + num[i];
    }

    int ans = 0;
    if(sum[0] % 7 == 0) ans = 1;
    for(int i = 0; i < n-1; i++){
        for(int j = 1; j < n; j++){
            int k = sum[j] - sum[i];
            if(k % 7 == 0){
                ans = max(ans, j-i);
            }
        }
    }
    cout << ans;

    return 0;
}