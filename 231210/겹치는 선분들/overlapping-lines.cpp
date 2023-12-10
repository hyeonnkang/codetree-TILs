#include <bits/stdc++.h>
using namespace std;

#define MX_N 100000
#define MX_V 1000000000

int n, k;
pair<int, int> line[MX_N+1]; // {왼쪽점, 오른쪽점}

int main() {
    cin >> n >> k;

    int cur_x = 0;
    for(int i = 0; i < n; i++){
        int m;
        char d;

        cin >> m >> d;

        if(d == 'L'){
            line[i] = {cur_x - m, cur_x};
            cur_x = cur_x - m;
        }else{
            line[i] = {cur_x, cur_x + m};
            cur_x = cur_x + m;
        }
    }

    // {좌표, +1 또는 -1, 선분번호}
    vector<tuple<int, int, int>> points;
    for(int i = 0; i < n; i++){
        points.push_back({line[i].first, +1, i});
        points.push_back({line[i].second, -1, i});
    }

    sort(points.begin(), points.end());

    

    int ans = 0; // k 이상 선분이 겹치는 범위의 길이의 합
    int start = 0; // k 이상 선분이 겹치는 곳의 시작점
    unordered_set<int> cur_lines; // 현재 범위안에 있는 선분들의 인덱스 집합
    for(int i = 0; i < (int)points.size(); i++){
        int x, val, idx;
        tie(x, val, idx) = points[i];

        if(val == 1){
            // 선분이 k 이상 겹치는 범위가 시작할 경우
            if((int)cur_lines.size() == k-1){
                start = x;
            }
            cur_lines.insert(idx);
        }else{
            // 선분이 k 이상 겹치는 범위가 끝날 경우
            if((int)cur_lines.size() == k){
                ans += x - start;
            }
            cur_lines.erase(idx);
        }
    }
    cout << ans;

    return 0;
}