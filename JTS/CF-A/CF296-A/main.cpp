//    Date : 2020-06-07
//  Author : Rahul Sharma
// Problem : A. Yaroslav and Permutations
//     Url : https://codeforces.com/contest/296/problem/A

#include <bits/stdc++.h>
using namespace std;

#define input(t, v) t v; cin >> v

int maxf(unordered_map<int, int>& f){
    int m = f.begin()->second;
    for(auto [k, v]: f)
        m = max(m, v);
    return m;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    input(int, n);
    unordered_map<int, int> f;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        f[x]++;
    }

    cout << (maxf(f) <= (n+1)/2 ? "YES": "NO") << '\n';
}
