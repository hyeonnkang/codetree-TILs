#include <bits/stdc++.h>
using namespace std;

#define MX_N 50000

int n;
tuple<int, int, int> line[MX_N]; // {y, x1, x2}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        if(x1 > x2){
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
        }
        line[i] = {y, x1, x2};
    }

    // {x좌표, +1 또는 -1, 선분번호}
    vector<tuple<int, int, int>> points;
    for(int i = 0; i < n; i++){
        points.push_back({get<1>(line[i]), +1, i});
        points.push_back({get<2>(line[i]), -1, i});
    }
    sort(points.begin(), points.end());

    set<pair<int, int>> cur;
    set<int> colors; // 보이는 선분의 인덱스 집합
    for(int i = 0; i < (int)points.size(); i++){
        int x, val, idx;
        tie(x, val, idx) = points[i];

        if(val == 1){
            cur.insert({get<0>(line[idx]), idx});
        }else{
            cur.erase({get<0>(line[idx]), idx});
        }
        
        if(!cur.empty()){
            colors.insert(cur.begin()->second);
        }
    }

    cout << (int)colors.size();

    return 0;
}