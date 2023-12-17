#include <bits/stdc++.h>
using namespace std;

#define MX_N 100000

int n;
pair<int, int> person[MX_N+1];

bool comp(tuple<int, int, int> a, tuple<int, int, int> b){
    // 날짜가 같을 경우, 새로 들어오는 사람이 먼저
    if(get<0>(a) == get<0>(b)){
        return get<1>(a) > get<1>(b); 
    }
    // 날짜가 다를 경우, 날짜가 작은 사람이 먼저
    else return get<0>(a) < get<0>(b);
}

int main() {
    // 입력받기
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> person[i].first >> person[i].second;
    }

    // {날짜, +1 또는 -1, 사람번호}
    vector<tuple<int, int, int>> hotel;
    for(int i = 1; i <= n; i++){
        hotel.push_back({person[i].first, 1, i});
        hotel.push_back({person[i].second, -1, i});
    }

    // 오름차순으로 정렬
    sort(hotel.begin(), hotel.end(), comp);

    // 탐색
    int ans = 0;
    int sum = 0;
    for(int i = 0; i < (int)hotel.size(); i++){
        int day, val, idx;
        tie(day, val, idx) = hotel[i];
        sum += val;
        ans = max(ans, sum);
    }
    cout << ans;

    return 0;
}