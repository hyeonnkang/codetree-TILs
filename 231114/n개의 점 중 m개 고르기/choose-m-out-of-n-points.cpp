#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MX 20
#define X first
#define Y second
#define INF 987654321

int n, m;
pair<int, int> dot[MX];
pair<int, int> selected_dot[MX];
ll ans = INF; // 거리가 가장 먼 두 점 사이의 거리의 최솟값

void getInput();
ll calculateMaxDist(); // 고른 점들의 거리의 최솟값을 반환
void selectDot(int cur, int cnt);

int main() {
    getInput();
    selectDot(0, 0);
    cout << ans;
    return 0;
}

ll calculateMaxDist(){   
    ll res = 0;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            int x = abs(selected_dot[i].X - selected_dot[j].X);
            int y = abs(selected_dot[i].Y - selected_dot[j].Y);
            res = max(res, ll(x*x + y*y));
        }
    }
    return res;
}

void selectDot(int cur, int cnt){
    if(cnt == m){ // m 개를 모두 고른 경우
        ans = min(ans, calculateMaxDist());
        return;
    }
    if(cur == n){ // n개의 점을 모두 탐색한 경우
        return;
    }

    // 현재 점을 선택한 경우
    selected_dot[cnt] = dot[cur];
    selectDot(cur+1, cnt+1);

    // 현재 점을 선택하지 않은 경우
    selectDot(cur+1, cnt);
}

void getInput(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> dot[i].X >> dot[i].Y;
    }
}