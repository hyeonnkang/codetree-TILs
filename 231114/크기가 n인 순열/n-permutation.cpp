#include <bits/stdc++.h>
using namespace std;

#define MAX_N 8

int n;
int num[MAX_N];
int visited[MAX_N+1];

void printNum(){
    for(int i = 0; i < n; i++){
        cout << num[i] << " ";
    }cout << "\n";
}

void selectNum(int cur){
    if(cur == n){
        printNum();
        return;
    }
    for(int i = 1; i <= n; i++){
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
    selectNum(0);

    return 0;
}