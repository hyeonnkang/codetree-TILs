#include <bits/stdc++.h>
using namespace std;

#define MX_N 100000

int n;
string s;
int R[MX_N]; // )) 의 갯수

int main() {
    cin >> s;
    n = (int)s.size();

    for(int i = n-2; i >= 0; i--){
        R[i] = R[i+1];
        if(s[i] == ')' && s[i] == s[i+1]){
            R[i]++;
        }
    }

    int sum = 0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == '(' && s[i] == s[i+1]){
            sum += R[i];
        }
    }
    cout << sum;

    return 0;
}