//    Date : 2019-03-29
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/152/problem/B

#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, y, x, k;
    cin >> n >> m >> y >> x >> k;

    uint64_t s = 0;
    for (int i = 0, dy, dx; i < k; i++) {
        cin >> dy >> dx;
        int sy = 0, sx = 0;
        if (dy < 0)
            sy = (1 - y) / dy;
        else if (dy > 0)
            sy = (n - y) / dy;
        if (dx < 0)
            sx = (1 - x) / dx;
        else if (dx > 0)
            sx = (m - x) / dx;
        if (sy < 0 || sx < 0)
            continue;
        int t = dx == 0 ? sy : (dy == 0 ? sx : min(sy, sx));
        int y1 = y + t * dy, x1 = x + t * dx;
        // cout << sy << ',' << sx << '|' << y1 << ',' << x1 << '\n';
        // if (0 < y1 && y1 <= n && 0 < x1 && x1 <= m)
        s += t, y = y1, x = x1;
    }

    cout << s << '\n';
}
