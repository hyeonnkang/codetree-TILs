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

    int j = n-1;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        while(j > i && num[i] + num[j] > k){
            j--;
        }
        if(j > i){
            ans += j-i;
        }
    }
    cout << ans;

    return 0;
}