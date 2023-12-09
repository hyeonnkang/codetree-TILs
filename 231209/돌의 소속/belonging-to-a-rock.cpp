#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n, q;
int group[MX+1];
tuple<int, int, int> prefix_sum[MX+1];

int main() {
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> group[i];
    }

    for(int i = 1; i <= n; i++){
        prefix_sum[i] = prefix_sum[i-1];
        switch(group[i]){
            case 1:
                get<0>(prefix_sum[i])++;
                break;
            case 2:
                get<1>(prefix_sum[i])++;
                break;
            case 3:
                get<2>(prefix_sum[i])++;
                break;
        }
    }

    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;

        cout << get<0>(prefix_sum[b]) - get<0>(prefix_sum[a-1]) << " "
        << get<1>(prefix_sum[b]) - get<1>(prefix_sum[a-1]) << " "
        << get<2>(prefix_sum[b]) - get<2>(prefix_sum[a-1]) << "\n";
    }
    
    return 0;
}