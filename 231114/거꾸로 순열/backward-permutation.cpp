#include <bits/stdc++.h>
using namespace std;

#define MX 8

int n;
int num[MX+1];
int visited[MX+1];

void printNum(){
    for(int i = 1; i <= n; i++){
        cout << num[i] << " ";
    }cout << "\n";
}

void selectNum(int cur){
    if(cur > n){
        printNum();
        return;
    }
    for(int i = n; i >= 1; i--){
        if(!visited[i]){
            visited[i] = 1;
            num[cur] = i;
            selectNum(cur+1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    selectNum(1);
    
    return 0;
}