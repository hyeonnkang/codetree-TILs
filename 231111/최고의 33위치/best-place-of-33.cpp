#include <bits/stdc++.h>
using namespace std;
#define MX 20

int n;
int arr[MX][MX];
int ans = 0;

bool isRangeValid(int i, int j){
    return (i+3 > n || j+3 > n);
}

void checkCoin(int x, int y){
    int sum = 0;
    for(int i = x; i < x+3; i++){
        for(int j = y; j < y+3; j++){
            if(arr[i][j]) sum++;
        }
    }
    ans = max(ans, sum);
}


int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            checkCoin(i, j);
        }
    }
    cout << ans;

    return 0;
}