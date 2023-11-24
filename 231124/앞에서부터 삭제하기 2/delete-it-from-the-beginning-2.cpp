#include <bits/stdc++.h>
using namespace std;

#define MX 100000

int n;
int num[MX+1];

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;   
    double ans = 0; 
    for(int i = n; i >= 1; i--){
        for(int j = n; j >= i; j--){
            pq.push(num[j]);
        }

        // 제일 작은 수 삭제
        pq.pop();
        if(pq.empty()) continue;

        // 평균 구해서 최대 평균값 업데이트
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top(); pq.pop();
        }
        double avg = (sum / double(n - i));
        ans = max(ans, avg);
    }

    cout << fixed;
    cout.precision(2);
    cout << ans << "\n";

    return 0;
}