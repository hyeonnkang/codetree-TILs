#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n, s;
int num[MX];
int ans = INT_MAX;

int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    for(int i = 0; i < n; i++){
        int sum = 0;
        int j = i;
        for(; j < n; j++){
            sum += num[j];
            if(sum >= s) break;
        }
        if(sum >= s) ans = min(ans, j-i+1);
    }
    cout << (ans == INT_MAX ? -1 : ans);
    
    return 0;
}