#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MX 100000

int n, k, b;
int arr[MX+1];
int prefix_sum[MX+1];

int getSum(int a, int b){
    return prefix_sum[b] - prefix_sum[a-1];
}

int main() {
    cin >> n >> k >> b;

    for(int i = 0; i < b; i++){
        int x;
        cin >> x;
        arr[x] = 1;
    }

    for(int i = 1; i <= n; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }

    int ans = INF;
    for(int i = 1; i <= n - k + 1; i++){
        ans = min(ans, getSum(i, i + k - 1));
    }
    cout << ans;

    return 0;
}