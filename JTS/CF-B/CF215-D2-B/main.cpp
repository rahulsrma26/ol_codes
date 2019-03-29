//    Date : 2019-03-29
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/215/problem/B

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

template <typename Comp>
int input(Comp c) {
    int n, m;
    cin >> n >> m;

    for (int i = 1, x; i < n; i++) {
        cin >> x;
        if (c(x, m))
            m = x;
    }
    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    auto r1 = input(greater<int>());
    auto p1 = input(greater<int>());
    auto p2 = input(less<int>());
    double A, B;
    cin >> A >> B;

    double r2 = r1 * sqrt(1.0 / (1.0 + (A * p2) / (B * p1)));
    cout << fixed << setprecision(12) << r2 << '\n';
}
