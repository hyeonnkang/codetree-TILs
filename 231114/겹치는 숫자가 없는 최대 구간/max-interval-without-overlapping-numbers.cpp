#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n;
int num[MX+1];
int visited[MX+1];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    int ans = 0;
    int j = 1;
    for(int i = 1; i <= n; i++){
        while(j <= n){
            if(visited[num[j]]) break;
            visited[num[j]]++;
            j++;
        }
        ans = max(ans, j-i);
        visited[num[i]]--;
    }
    cout << ans;

    return 0;
}