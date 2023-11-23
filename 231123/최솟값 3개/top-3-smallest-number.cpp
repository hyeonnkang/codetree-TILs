#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
multiset<int> tree_set;
vector<ll> answer;

ll getMulResult(){
    auto it = tree_set.begin();
    int k = 0;
    ll res = 1;
    while(k < 3){
        res *= (*it);
        it++;
        k++;
    }
    return res;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        tree_set.insert(x);

        if(i < 2) 
            answer.push_back(-1);
        else 
            answer.push_back(getMulResult());
    }

    for(auto it = answer.begin(); it != answer.end(); it++){
        cout << *it << "\n";
    }

    return 0;
}