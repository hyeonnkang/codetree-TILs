#include <bits/stdc++.h>
using namespace std;

#define MX 15
#define x1 first
#define x2 second

pair<int, int> line[MX];

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.x2 != b.x2) return (a.x2 < b.x2);
    else{
        return (a.x1 < b.x1);
    }
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> line[i].x1 >> line[i].x2;
    }

    sort(line, line+n, comp);

    int pre = 0; // 이전에 선택한 선분의 끝점
    int ans = 0; // 뽑은 선분의 수
    for(int i = 0; i < n; i++){
        if(line[i].x1 > pre){
            pre = line[i].x2;
            ans++;
        }
    }
    cout << ans;

    return 0;
}