#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n, k;
int num[MX];

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    unordered_map<int, int> num_cnt;
    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        while(j < n){
            if(num_cnt[num[j]] + 1 > k) break;
            num_cnt[num[j]]++;
            j++;
        }
        ans = max(ans, j-i);
        num_cnt[num[i]]--;
    }
    cout << ans;

    return 0;
}