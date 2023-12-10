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

    // (x좌표, +1 또는 -1, 선분 번호)
    vector<tuple<int, int, int>> points;

    for(int i = 0; i < n; i++){
        points.push_back({line[i].first, +1, i}); // 시작점
        points.push_back({line[i].second, -1, i}); // 끝점
    }

    sort(points.begin(), points.end());

    // 현재 그룹에 포함된 선분
    unordered_set<int> cur;
    int ans = 0; // 총 그룹의 수
    for(int i = 0; i < (int)points.size(); i++){
        if(get<1>(points[i]) == 1){ // 선분이 시작할 경우
            if((int)cur.size() == 0){
                ans++;
            }
            cur.insert(get<2>(points[i]));
        }else{ // 선분이 끝나는 경우
            cur.erase(get<2>(points[i]));
        }   
    }
    cout << ans;

    return 0;
}