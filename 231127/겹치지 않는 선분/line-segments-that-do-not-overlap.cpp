#include <bits/stdc++.h>
using namespace std;

#define MX 100000

#define X1 first
#define X2 second

int n;
pair<int, int> dot[MX];
int L[MX];
int R[MX];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dot[i].X1 >> dot[i].X2;
    }

    L[0] = dot[0].X2;
    for(int i = 1; i < n; i++){
        L[i] = max(L[i-1], dot[i].X2);
    }
    R[n-1] = dot[n-1].X2;
    for(int i = n-2; i >= 0; i--){
        R[i] = min(R[i+1], dot[i].X2);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(L[i] <= R[i]) ans++;
    }
    cout << ans;

    return 0;
}