#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define MX_N 100000
#define X first
#define Y second

int n;
pair<int, int> checkpoint[MX_N];
int L[MX_N];
int R[MX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> checkpoint[i].X >> checkpoint[i].Y;
    }

    for(int i = 1; i < n; i++){
        L[i] = L[i-1] + abs(checkpoint[i].X - checkpoint[i-1].X) + abs(checkpoint[i].Y - checkpoint[i-1].Y);
    }

    for(int i = n-2; i >= 0; i--){
        R[i] = R[i+1] + abs(checkpoint[i].X - checkpoint[i+1].X) + abs(checkpoint[i].Y - checkpoint[i+1].Y);
    }

    int ans = INF;
    for(int i = 1; i < n-1; i++){
        // i번 체크포인트를 건너뛸 경우
        int dist = L[i-1] + R[i+1] +  abs(checkpoint[i-1].X - checkpoint[i+1].X) + abs(checkpoint[i-1].Y - checkpoint[i+1].Y);
        ans = min(ans, dist);
    }
    cout << ans;

    return 0;
}