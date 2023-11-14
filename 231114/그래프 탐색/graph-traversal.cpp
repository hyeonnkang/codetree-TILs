#include <bits/stdc++.h>
using namespace std;

#define MX 1000

int n, m;
vector<int> edges[MX+1];
int visited[MX+1];
int ans = 0;

void getInput();
void dfs(int cur);

int main() {
    getInput();

    visited[1] = 1;
    dfs(1);

    for(int i = 1; i <= n; i++){
        if(visited[i]) ans++;
    }
    cout << ans-1;

    return 0;
}

void dfs(int cur){
    for(auto it = edges[cur].begin(); it != edges[cur].end(); it++){
        if(visited[*it]) continue;
        visited[*it] = 1;
        dfs(*it);
    }
}

void getInput(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
}