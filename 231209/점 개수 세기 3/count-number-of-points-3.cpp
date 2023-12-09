#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n, q;
int ishere[MX+1];
int prefix_sum[MX+1];

int main() {
    cin >> n >> q;

    set<int> dot;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        dot.insert(x);
    }

    unordered_map<int, int> pos;
    int idx = 1;
    for(auto it = dot.begin(); it != dot.end(); it++){
        pos[*it] = idx++;
        ishere[pos[*it]] = 1;
    }

    for(int i = 1; i <= n; i++){
        prefix_sum[i] = prefix_sum[i-1] + ishere[i];
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        cout << prefix_sum[pos[b]] - prefix_sum[pos[a]-1] << "\n";
    }

    return 0;
}