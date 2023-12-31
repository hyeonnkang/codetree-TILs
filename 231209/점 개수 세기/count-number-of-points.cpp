#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    set<int> num;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        num.insert(x);
    }

    unordered_map<int, int> pos;
    int idx = 1;
    for(auto it = num.begin(); it != num.end(); it++){
        pos[*it] = idx++;
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        set<int>::iterator it1 = num.lower_bound(a);
        set<int>::iterator it2 = num.upper_bound(b);

        if(it1 == num.end()){
            cout << 0 << "\n";
            continue;
        }

        bool flag = false;
        if(it2 == num.end()){
            it2--;
            flag = true;
        }
        int k = pos[*it2] - pos[*it1];
        if(flag) k++;
        cout << k << "\n";
    }

    return 0;
}