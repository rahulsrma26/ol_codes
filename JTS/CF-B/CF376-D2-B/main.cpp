//    Date : 2019-06-20
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/376/problem/B

#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        d[a - 1] += c;
        d[b - 1] -= c;
    }

    cout << accumulate(d.begin(), d.end(), 0, [](auto a, auto b){
        return b > 0 ? a + b : a;
    }) << '\n';
}
