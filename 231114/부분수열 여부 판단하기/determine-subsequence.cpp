#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n, m;
int A[MX];
int B[MX];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int j = 0; j < m; j++){
        cin >> B[j];
    }

    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(A[i] == B[j]){
            j++;
        }
        i++;
    }
    cout << (j == m ? "Yes" : "No"); 

    return 0;
}