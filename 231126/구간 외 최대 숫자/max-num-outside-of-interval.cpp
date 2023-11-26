#include <bits/stdc++.h>
using namespace std;

#define MX_N 100000

int n, q;
int num[MX_N+1];
int L[MX_N+1];
int R[MX_N+1];

int main() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    for(int i = 1; i <= n; i++){
        L[i] = max(L[i-1], num[i]);
    }
    R[n] = num[n];
    for(int i = n-1; i >= 1; i--){
        R[i] = max(R[i+1], num[i]);
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        cout << max(L[a-1], R[b+1]) << "\n";
    }

    return 0;
}