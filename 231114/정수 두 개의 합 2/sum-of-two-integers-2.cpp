#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n, k;
int num[MX];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num, num+n);

    int j = 1;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        j= i+1;
        while(j < n){
            if(num[i] + num[j] > k) break;
            ans++;
            j++;
        }
        if(j == n) j = n-1;
    }
    cout << ans;

    return 0;
}