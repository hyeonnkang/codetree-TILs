#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000

int n, m;
int num[MAX_N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    int sum = 0;
    int j = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(j < n){
            if(sum >= m) break;
            sum += num[j];
            j++;
        }
        if(sum == m) ans++;
        sum -= num[i];
    }
    cout << ans;

    return 0;
}