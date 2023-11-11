#include <bits/stdc++.h>
using namespace std;

#define MX 100

int arr[MX][MX];

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    // 행 갯수 세기
    for(int i = 0; i < n; i++){
        int pre = -1;
        int cnt = 1;
        for(int j = 0; j < n; j++){
            if(pre != arr[i][j]){
                cnt = 1;
            }else{
                cnt++;
            }
            pre = arr[i][j];
            if(cnt >= m){
                ans++;
                break;
            }
        }
    }

    // 열 갯수 세기
    for(int i = 0; i < n; i++){
        int pre = -1;
        int cnt = 1;
        for(int j = 0; j < n; j++){
            if(pre != arr[j][i]){
                cnt = 1;
            }else{
                cnt++;
            }
            pre = arr[j][i];
            if(cnt >= m){
                ans++;
                break;
            }
        }
    }
    cout << ans;

    return 0;
}