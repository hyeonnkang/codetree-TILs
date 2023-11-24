#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n;
int num[MX+1];
int sum[MX+1];
int min_num[MX+1];

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    sum[n] = num[n];
    for(int i = n-1; i >= 1; i--){
        sum[i] = sum[i+1] + num[i];
    }

    min_num[n] = num[n];
    for(int i = n-1; i >= 1; i--){
        min_num[i] = (num[i] < min_num[i+1]) ? num[i]: min_num[i+1];
    }
    
    double ans = 0;
    for(int i = n-1; i >= 1; i--){
        ans = max(ans, (sum[i] - min_num[i]) / double(n-i));
    }

    cout << fixed;
    cout.precision(2);
    cout << ans << "\n";

    return 0;
}