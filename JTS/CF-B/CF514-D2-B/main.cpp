//    Date : 2019-09-07
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/514/problem/B

#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    unordered_set<int> set;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        x -= a;
        y -= b;
        // cout << x << ',' << y << '\t';
        bool s = (x < 0) ^ (y < 0);
        if (x == 0 || y == 0)
            s = 0;
        x = std::abs(x);
        y = std::abs(y);
        auto d = std::gcd(x, y);
        // cout << s << '|' << d << '\t';
        x /= d;
        y /= d;
        int v = (x << 16) | y;
        set.insert(s ? -v : v);
        // cout << x << ',' << y << '\t' << v << '\n';
    }

    cout << set.size() << '\n';
}
