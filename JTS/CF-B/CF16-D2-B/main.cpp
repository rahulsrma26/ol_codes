//    Date : 2019-03-20
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/16/problem/B

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(m);
    for (auto& x : a)
        cin >> x.first >> x.second;

    sort(a.begin(), a.end(),
         [](const auto& x, const auto& y) { return x.second > y.second; });

    int t = 0;
    for (auto& x : a) {
        if (x.first >= n) {
            t += x.second * n;
            break;
        }
        t += x.second * x.first;
        n -= x.first;
    }
    cout << t << '\n';
}
