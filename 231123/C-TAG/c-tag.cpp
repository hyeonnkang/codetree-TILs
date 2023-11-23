#include <bits/stdc++.h>
using namespace std;

#define MAX_N 500
#define MAX_M 50

int n, m;
string A[MAX_N+1];
string B[MAX_N+1];

int selected[MAX_M];
int ans = 0;

void selectChar(int idx, int cnt){
    if(cnt >= 3){
        // 3개를 모두 고름  
        unordered_set<string> hash_set;
        // A를 모두 넣기
        for(int i = 1; i <= n; i++){
            string tmp = "";
            for(int j = 0; j < m; j++){
                if(selected[j]){
                    tmp += A[i][j];
                }
            }
            hash_set.insert(tmp);
        }
        // B가 있는지 확인
        bool flag = true;
        for(int i = 1; i <= n; i++){
            string tmp = "";
            for(int j = 0; j < m; j++){
                if(selected[j]){
                    tmp += B[i][j];
                }
            }
            if(hash_set.find(tmp) != hash_set.end()){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
        return;
    }
    if(idx >= m) return; // 3개를 모두 고르지 않았지만 모두 탐색을 끝낸 경우

    for(int i = idx; i < m; i++){
        if(!selected[i]){
            selected[i] = 1;
            selectChar(i+1, cnt+1);
            selected[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> B[i];
    }

    selectChar(0, 0);

    cout << ans;

    return 0;
}