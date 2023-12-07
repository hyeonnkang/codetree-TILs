#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n, k, b;
int isexists[MX+1];
int psum[MX+1];

int main() {
    cin >> n >> k >> b;

    fill(isexists + 1, isexists + n + 1, 1);
    for(int i = 0; i < b; i++){
        int x;
        cin >> x;
        isexists[x] = 0;
    }

    for(int i = 1; i <= n; i++){
        if(isexists[i]){
            psum[i] = psum[i-1] + 1;
        }else{
            psum[i] = psum[i-1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, psum[i]);
    }
    cout << max(k - ans, 0);

    return 0;
}

// 1~10 중 5개의 숫자가 빠져있다.
// 최소 한 세트가 6개
// 5개의 없는 숫자들 중 추가해야하는 숫자 갯수의 최솟값은?

// 빠진 숫자 : 2, 10, 1, 5, 9
// 현재 있는 숫자
// 3, 4, 6, 7, 8 -> 5를 넣으면 6개가 된다.

// num : 1 2 3 4 5 6 7 8 9 10
// exist 0 0 1 1 0 1 1 1 0 0
// psum  0 0 1 2 0 1 2 3 0 0