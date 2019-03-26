//    Date : 2019-03-26
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/433/problem/B

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;
    using num = long long;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<num> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<num> b(a);
    sort(b.begin(), b.end());

    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        b[i] += b[i - 1];
    }

    int m;
    cin >> m;
    while (m--) {
        int q, l, r;
        cin >> q >> l >> r;
        auto& v = q == 1 ? a : b;
        cout << v[r] - v[l - 1] << '\n';
    }
}
