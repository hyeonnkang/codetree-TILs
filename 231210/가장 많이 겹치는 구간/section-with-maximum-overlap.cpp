#include <bits/stdc++.h>
using namespace std;

#define MX 100000
#define MX_X 200000

int n;
pair<int, int> line[MX+1];
int cnt[MX_X+1];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> line[i].first >> line[i].second;
        cnt[line[i].first] += 1;
        cnt[line[i].second] -= 1;
    }

    int ans = 0;
    int sum = 0;
    for(int i = 1; i <= MX_X; i++){
        sum += cnt[i];
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}