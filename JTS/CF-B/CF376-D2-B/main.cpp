//    Date : 2019-06-20
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/376/problem/B

#include <iostream>
#include <vector>

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

    int t = 0;
    for (auto x : d)
        t += x > 0 ? x: 0;
    cout << t << '\n';
}
