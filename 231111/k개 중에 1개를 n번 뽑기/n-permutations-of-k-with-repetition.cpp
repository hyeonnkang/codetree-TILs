#include <bits/stdc++.h>
using namespace std;

#define MX 8

int k, n;
int chosen_num[MX];

// cnt : 현재 고른 숫자 갯수
void choose(int cnt){
    if(cnt == n){
        for(int i = 0; i < n; i++){
            cout << chosen_num[i] << " ";
        }cout << "\n";
        return;
    }

    for(int i = 1; i <= k; i++){
        chosen_num[cnt] = i;
        choose(cnt+1);
    }
}

int main() {
    cin >> k >> n;

    choose(0);

    return 0;
}