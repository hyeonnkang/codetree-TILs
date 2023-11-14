#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int num[MX];

int main() {
    int n, s;
    cin >> n >> s;

    for(int i = 0; i< n; i++){
        cin >> num[i];
    }

    int min_size = INT_MAX;
    int sum = 0;
    int j = -1;
    for(int i = 0; i < n; i++){
        while(sum < s && j+1 < n){
            sum += num[j+1];
            j++;
        }
        if(sum < s) break;
        int cur_size = j - i + 1;
        min_size = min(min_size, cur_size);
        sum -= num[i];
    }
    cout << (min_size == INT_MAX ? -1 : min_size);

    return 0;
}