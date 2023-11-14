#include <bits/stdc++.h>
using namespace std;

string s;
int k;
int cnt[26];

int main() {
    cin >> s >> k;

    int n = (int)s.size();

    int ans = 0;
    int j = 0;
    int idx = 0;
    int cur = 0;
    for(int i = 0; i < n; i++){
        while(j < n){
            idx = s[j]-'a';
            if(cnt[idx] == 0 && cur == k ) break;

            if(cnt[idx] == 0) cur++;
            cnt[idx]++;
            j++;
        }
        ans = max(ans, j-i);
        idx = s[i] - 'a';
        cnt[idx]--;
        if(cnt[idx] == 0) cur--;
    }
    cout << ans;

    return 0;
}