#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MX 100000

int n;
string s;
int L[MX]; // C의 갯수
int R[MX]; // W의 갯수

int main() {
    cin >> n;
    cin >> s;

    if(s[0] == 'C') L[0] = 1;
    for(int i = 1; i < n; i++){
        L[i] = L[i-1];
        if(s[i] == 'C') L[i]++;
    }
    if(s[n-1] == 'W') R[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        R[i] = R[i+1];
        if(s[i] == 'W') R[i]++;
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'O') ans += L[i] * R[i];
    }
    cout << ans;

    return 0;
}