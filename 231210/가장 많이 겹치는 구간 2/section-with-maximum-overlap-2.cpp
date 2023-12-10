#include <bits/stdc++.h>
using namespace std;

#define MX_N 100000

int n;
pair<int, int> line[MX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> line[i].first >> line[i].second;
    }

    // {좌표, +1 또는 -1, 선분 번호}
    vector<tuple<int, int, int>> points;
    for(int i = 0; i < n; i++){
        points.push_back({line[i].first, +1, i});
        points.push_back({line[i].second, -1, i});
    }

    // 정렬
    sort(points.begin(), points.end());

    int max_cnt = 0; // 가장 많이 겹치는 선의 갯수
    int cur_cnt = 0; // 현재 선의 갯수
    unordered_set<int> cur;
    for(int i = 0; i < (int)points.size(); i++){
        int x, val, idx;
        tie(x, val, idx) = points[i];

        if(val == 1){
            cur_cnt += 1;
            max_cnt = max(max_cnt, cur_cnt);
            cur.insert(idx);
        }else{
            cur_cnt -= 1;
            cur.erase(idx);
        }
    }
    cout << max_cnt;

    return 0;
}