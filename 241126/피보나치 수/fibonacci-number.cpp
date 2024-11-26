#include <bits/stdc++.h>
using namespace std;

int n;

int func(int k){
    if(k == 1 || k == 2) return 1;
    else return func(k-1) + func(k-2); 
}

int main() {
    cin >> n;
    cout << func(n);
    return 0;
}