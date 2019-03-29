//    Date : 2019-03-29
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/186/problem/B

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;

    double tx = t1 * (1 - k / 100.0);
    auto [tmin, tmax] = minmax({tx, (double)t2});

    vector<pair<double, int>> a;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        auto [rmin, rmax] = minmax({x, y});
        a.push_back({rmin * tmin + rmax * tmax, i});
    }
    sort(a.begin(), a.end(), [](auto& x, auto& y) {
        if (x.first != y.first)
            return x.first > y.first;
        return x.second < y.second;
    });

    for (auto& [h, i] : a)
        cout << i << ' ' << fixed << setprecision(2) << h << '\n';
}
