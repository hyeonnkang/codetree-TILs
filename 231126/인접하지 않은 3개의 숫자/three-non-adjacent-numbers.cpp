#include <bits/stdc++.h>
using namespace std;

#define MX_N 100000

int n;
int num[MX_N+1];
int L[MX_N+1];
int R[MX_N+1];

void getInput();
void setLAndR();
int select3Num();

int main() {
    getInput();
    setLAndR();
    cout << select3Num();
    return 0;
}

int select3Num(){
    int res = 0;
    for(int i = 3; i <= n-2; i++){
        res = max(res, L[i-2] + R[i+2] + num[i]);
    }
    return res;
}

void getInput(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }
}

void setLAndR(){
    for(int i = 1; i <= n; i++){
        L[i] = max(L[i-1], num[i]);
    }
    R[n] = num[n];
    for(int i = n-1; i >= 1; i--){
        R[i] = max(R[i+1], num[i]);
    }
}