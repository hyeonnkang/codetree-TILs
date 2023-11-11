#include <bits/stdc++.h>

using namespace std;

#define MX 200

int n, m;
int arr[MX][MX];

// block1 : ㄱ 모양 블럭
int block1_x[][3] = {
        {0, 1, 1},
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 0}
};
int block1_y[][3] = {
        {0, 0, 1},
        {0, 0, 1},
        {0, 1, 1},
        {0, 1, 1}
};

// block2 : ㅡ 모양 블럭
int block2_x[][3] = {
        {0, 1, 2},
        {0, 0, 0}
};
int block2_y[][3] = {
        {0, 0, 0},
        {0, 1,}
};

// x, y가 영역의 범위 밖에 있으면 true 반환
bool isNotValidRange(int x, int y) {
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int ans = 0;

// block1의 숫자 합 확인
void checkBlock1(int i, int j) {
    for (int b = 0; b < 4; b++) {
        int x, y;
        bool flag = true;
        int sum = 0;
        for (int idx = 0; idx < 3; idx++) {
            x = i + block1_x[b][idx];
            y = j + block1_y[b][idx];

            if (isNotValidRange(x, y)) {
                flag = false;
                break;
            }
            sum += arr[x][y];
        }

        if (flag) {
            ans = max(ans, sum);
        }
    }
}

// block2의 숫자 합 확인
void checkBlock2(int i, int j) {
    // block2 체크
    for (int b = 0; b < 2; b++) {
        int x, y;
        bool flag = true;
        int sum = 0;
        for (int idx = 0; idx < 3; idx++) {
            x = i + block2_x[b][idx];
            y = j + block2_y[b][idx];

            if (isNotValidRange(x, y)) {
                flag = false;
                break;
            }
            sum += arr[x][y];
        }

        if (flag) {
            ans = max(ans, sum);
        }
    }
}


int main() {
    // 입력받기
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // 블럭을 탐색하며 최대합 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            checkBlock1(i, j);
            checkBlock2(i, j);
        }
    }

    // 정답 출력
    cout << ans;

    return 0;
}