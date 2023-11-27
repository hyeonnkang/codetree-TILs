#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n;
char game[MX];
tuple<int, int, int> left_cnt[MX]; // {주먹, 가위, 보자기} 갯수
tuple<int, int, int> right_cnt[MX]; // {주먹, 가위, 보자기} 갯수
int L[MX];
int R[MX];

void getInput();
void countLeftCnt();
void countRightCnt();
void countL();
void countR();
int getMaxWinCnt();

int main() {
    getInput();
    countLeftCnt();
    countRightCnt();
    countL();
    countR();
    cout << getMaxWinCnt();

    return 0;
}

int getMaxWinCnt(){
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        ans = max(ans, L[i] + R[i+1]);
    }
    return ans;
}

void countL(){
    for(int i = 0; i < n; i++){
        L[i] = max(get<0>(left_cnt[i]), get<1>(left_cnt[i]));
        L[i] = max(L[i], get<2>(left_cnt[i]));
    }
}

void countR(){
    for(int i = 0; i < n; i++){
        R[i] = max(get<0>(right_cnt[i]), get<1>(right_cnt[i]));
        R[i] = max(R[i], get<2>(right_cnt[i]));
    }
}

void countRightCnt(){
    switch(game[n-1]){
        case 'H':
            right_cnt[n-1] = {1, 0, 0};
            break;
        case 'S':
            right_cnt[n-1] = {0, 1, 0};
            break;
        case 'P':
            right_cnt[n-1] = {0, 0, 1};
            break;
    }
    for(int i = n-2; i >= 0; i--){
        switch(game[i]){
            case 'H':
                right_cnt[i] = {get<0>(right_cnt[i+1]) + 1, get<1>(right_cnt[i+1]), get<2>(right_cnt[i+1])};
                break;
            case 'S':
                right_cnt[i] = {get<0>(right_cnt[i+1]), get<1>(right_cnt[i+1]) + 1, get<2>(right_cnt[i+1])};
                break;
            case 'P':
                right_cnt[i] = {get<0>(right_cnt[i+1]), get<1>(right_cnt[i+1]), get<2>(right_cnt[i+1]) + 1};
                break;
        }
    }
}

void countLeftCnt(){
    switch(game[0]){
        case 'H':
            left_cnt[0] = {1, 0, 0};
            break;
        case 'S':
            left_cnt[0] = {0, 1, 0};
            break;
        case 'P':
            left_cnt[0] = {0, 0, 1};
            break;
    }
    for(int i = 1; i < n; i++){
        switch(game[i]){
            case 'H':
                left_cnt[i] = {get<0>(left_cnt[i-1]) + 1, get<1>(left_cnt[i-1]), get<2>(left_cnt[i-1])};
                break;
            case 'S':
                left_cnt[i] = {get<0>(left_cnt[i-1]), get<1>(left_cnt[i-1]) + 1, get<2>(left_cnt[i-1])};
                break;
            case 'P':
                left_cnt[i] = {get<0>(left_cnt[i-1]), get<1>(left_cnt[i-1]), get<2>(left_cnt[i-1]) + 1};
                break;
        }
    }
}

void getInput(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> game[i];
    }
}