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
    int j = 0;
    for(int i = 1; i <= n; i++){
        while(j+1 <= n && !visited[num[j+1]]){
            visited[num[j+1]]++;
            j++;
        }
        ans = max(ans, j-i+1);
        visited[i]--;
    }
    cout << ans;

    return 0;
}