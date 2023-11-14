#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n;
int num[MX];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num, num+n);

    int j = n-1;
    int ans = INT_MAX;
    for(int i = 0; i < n-1; i++){
        while(j > i){
            if(abs(num[i]+num[j]) < abs(ans)){
                ans = abs(num[i]+num[j]);
            }
            
            if(num[i]+num[j] > 0) j--;
            else break;
        }
    }
    cout << ans;

    return 0;
}