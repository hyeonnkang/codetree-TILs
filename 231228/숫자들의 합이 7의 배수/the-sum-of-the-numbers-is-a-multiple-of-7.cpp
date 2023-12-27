#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MX_N 50000

int n;
int num[MX_N];
ll sum[MX_N];
vector<int> cnt[7];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    sum[0] = num[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + num[i];
    }

    for(int i = 0; i < n; i++){
        int idx = sum[i] % 7;
        cnt[idx].push_back(i);
    }

    for(int i = 0; i < 7; i++){
        sort(cnt[i].begin(), cnt[i].end());
    }

    int ans = 0;
    for(int i = 0; i < 7; i++){
        if(cnt[i].size() > 1){
            auto it = cnt[i].begin();
            int a = *it;
            it = cnt[i].end();
            it--;
            int b = *it;
            ans = max(ans, b-a);
        }else if(cnt[i].size() == 1){
            if(i % 7 == 0){
                ans = max(ans, 1);
            }
        }
    }
    cout << ans;

    return 0;
}