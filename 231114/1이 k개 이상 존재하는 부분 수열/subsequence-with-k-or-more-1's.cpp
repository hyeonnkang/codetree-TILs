#include <bits/stdc++.h>
using namespace std;

#define MX 1000000

int num[MX];

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    int ans = INT_MAX;
    int cnt = 0; // 1의 갯수
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < n){
            if(cnt == k) break;
            if(num[j] == 1){
                cnt++;
            }
            j++;
        }
        if(cnt >= k)
            ans = min(ans, j-i);
        if(num[i] == 1) cnt--;
    }
    cout << ans;

    return 0;
}