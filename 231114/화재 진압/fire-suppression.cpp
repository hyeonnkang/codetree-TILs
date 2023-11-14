#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n, m;
int fire_pos[MX];
int hero_pos[MX];
int fire_dist[MX];

void getInput();

int main() {
    getInput();

    sort(fire_pos, fire_pos+n);
    sort(hero_pos, hero_pos+m);

    fill(fire_dist, fire_dist + n, INT_MAX);

    int j = 0;
    for(int i = 0; i < n; i++){
        if(j == m) j--;
        while(j < m){
            int dist = abs(hero_pos[j] - fire_pos[i]);
            if(fire_dist[i] < dist) break;
            fire_dist[i] = min(fire_dist[i], dist);
            j++;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, fire_dist[i]);
    }
    cout << ans;

    return 0;
}

void getInput(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> fire_pos[i];
    }
    for(int j = 0; j < m; j++){
        cin >> hero_pos[j];
    }
}