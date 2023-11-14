#include <bits/stdc++.h>
using namespace std;

string s;
int visited[26];

int main() {
    cin >> s;

    int sz = (int)s.size();
    int ans = 0;
    int j = 0;
    for(int i = 0; i < sz; i++){
        while(j < sz){
            if(visited[s[j]-'a']) break;

            visited[s[j]-'a'] = 1;
            j++;
        }
        ans = max(ans, j-i);
        visited[s[i]-'a'] = 0;
    }
    cout << ans;

    return 0;
}