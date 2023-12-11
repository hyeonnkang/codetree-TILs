#include <bits/stdc++.h>
using namespace std;

#define MX_N 100000

int n;
pair<int, int> use[MX_N+1];

int com[MX_N+1]; // com[i] : i번 사람이 사용하는 컴퓨터번호

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> use[i].first >> use[i].second;
    }

    // {시간, +1(사용시작) 또는 -1(사용종료), 사람번호}
    vector<tuple<int, int, int>> times;
    for(int i = 1; i <= n; i++){
        times.push_back({use[i].first, +1, i});
        times.push_back({use[i].second, -1, i});
    }

    sort(times.begin(), times.end());

    // 사용가능한 컴퓨터 1~n 까지 우선순위큐에 저장
    priority_queue<int, vector<int>, greater<int>> empty_computer;
    for(int i = 1; i <= n; i++){
        empty_computer.push(i);
    }

    for(int i = 0; i < (int)times.size(); i++){
        int tm, val, person;
        tie(tm, val, person) = times[i];

        if(val == 1){ // 새로운 사람이 컴퓨터 사용 시작
            com[person] = empty_computer.top();
            empty_computer.pop();
        }else{ // 사람이 컴퓨터 사용 종료
            empty_computer.push(com[person]);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << com[i] << " ";
    }

    return 0;
}