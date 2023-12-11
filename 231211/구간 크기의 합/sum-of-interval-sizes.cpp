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

    // {좌표, +1 또는 -1, 선분번호}
    vector<tuple<int, int, int>> points;
    for(int i = 0; i < n; i++){
        points.push_back({line[i].first, +1, i});
        points.push_back({line[i].second, -1, i});
    }

    sort(points.begin(), points.end());

    int ans = 0; // 총 구간의 길이의 합
    int start = 0; // 구간이 시작한 좌표
    int sum = 0; // 현재 구간 내의 선분의 갯수
    for(int i = 0; i < (int)points.size(); i++){
        int x, val, idx;
        tie(x, val, idx) = points[i];

        if(val == 1){ // 새로운 선분 시작
            if(sum == 0){ // 새로운 구간이 시작할 경우
                start = x;
            }
            sum += val;
        }else{ // 선분 끝
            sum += val;
            if(sum == 0){ // 구간이 종료될 경우
                ans += x - start;
            }
        }
    }
    cout << ans;

    return 0;
}