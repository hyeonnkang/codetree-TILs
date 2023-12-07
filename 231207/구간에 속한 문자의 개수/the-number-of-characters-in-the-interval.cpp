#include <bits/stdc++.h>
using namespace std;

#define MX 1000

int n, m, k;
char mat[MX+1][MX+1];
tuple<int, int, int> sum[MX+1][MX+1];

int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < (int)s.size(); j++){
            mat[i][j+1] = s[j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] = {
                get<0>(sum[i-1][j]) + get<0>(sum[i][j-1]) - get<0>(sum[i-1][j-1]),
                get<1>(sum[i-1][j]) + get<1>(sum[i][j-1]) - get<1>(sum[i-1][j-1]),
                get<2>(sum[i-1][j]) + get<2>(sum[i][j-1]) - get<2>(sum[i-1][j-1])
            };
            switch(mat[i][j]){
                case 'a':
                    get<0>(sum[i][j])++;  
                    break;
                case 'b':
                    get<1>(sum[i][j])++;  
                    break;
                case 'c':
                    get<2>(sum[i][j])++;  
                    break;
            }
        }
    }

    for(int i = 0; i < k; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int a = get<0>(sum[r2][c2]) - get<0>(sum[r1-1][c2]) - get<0>(sum[r2][c1-1]) + get<0>(sum[r1-1][c1-1]);
        int b = get<1>(sum[r2][c2]) - get<1>(sum[r1-1][c2]) - get<1>(sum[r2][c1-1]) + get<1>(sum[r1-1][c1-1]);
        int c = get<2>(sum[r2][c2]) - get<2>(sum[r1-1][c2]) - get<2>(sum[r2][c1-1]) + get<2>(sum[r1-1][c1-1]);
        cout << a << " " << b << " " << c << "\n";
    }

    return 0;
}