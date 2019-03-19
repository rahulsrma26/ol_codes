//    Date : 2019-03-19
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/127/problem/A

#include <bits/stdc++.h>

constexpr double sqr(int x) { return x * x; }

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    double d = 0;
    int x1, y1;
    cin >> x1 >> y1;

    for (int i = 1, x2, y2; i < n; i++) {
        cin >> x2 >> y2;
        d += sqrt(sqr(x2 - x1) + sqr(y2 - y1)) / 50.0;
        x1 = x2;
        y1 = y2;
    }

    cout << fixed << setprecision(9) << d * k;
}
