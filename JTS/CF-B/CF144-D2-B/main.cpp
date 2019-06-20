//    Date : 2019-04-08
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/144/problem/B

#include <algorithm>
#include <iostream>
#include <vector>


struct circle {
    int x, y, r;
};

template <class T>
T sqr(T x) {
    return x * x;
}

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int xa, ya, xb, yb, n;
    cin >> xa >> ya >> xb >> yb >> n;

    if (xa > xb)
        swap(xa, xb);
    if (ya > yb)
        swap(ya, yb);

    vector<circle> cls(n);
    for (auto& c : cls)
        cin >> c.x >> c.y >> c.r;

    auto is_inside = [&](const int x, const int y) {
        for (const auto& c : cls)
            if (sqr(c.x - x) + sqr(c.y - y) <= sqr(c.r))
                return true;
        return false;
    };

    int ctr = 2 * (xb - xa + yb - ya);
    for (int i = xa; i <= xb; i++) {
        if (is_inside(i, ya))
            ctr--;
        if (is_inside(i, yb))
            ctr--;
    }

    for (int i = ya + 1; i < yb; i++) {
        if (is_inside(xa, i))
            ctr--;
        if (is_inside(xb, i))
            ctr--;
    }

    cout << ctr << '\n';
}
