#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_set<int> a;
unordered_set<int> b;
unordered_set<int> result;

void getInput();
void getDisjointSet();

int main() {
    getInput();

    getDisjointSet();

    // 대칭 차집합의 갯수 출력
    cout << result.size();

    return 0;
}

void getDisjointSet(){
    // a - b 구하기
    for(auto it = a.begin(); it != a.end(); it++){
        if(b.find(*it) == b.end()){
            result.insert(*it);
        }
    }

    // b - a 구하기
    for(auto it = b.begin(); it != b.end(); it++){
        if(a.find(*it) == b.end()){
            result.insert(*it);
        }
    }
}

void getInput(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
    }

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        b.insert(x);
    }
}