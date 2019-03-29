//    Date : 2019-03-28
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/469/problem/B

#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p, q, l, r;
    cin >> p >> q >> l >> r;

    vector<pair<int, int>> a(p), b(q);
    for (auto& [x, y] : a)
        cin >> x >> y;
    for (auto& [x, y] : b)
        cin >> x >> y;

    auto is_common = [&](int t) {
        int x = 0, y = 0;
        while (x < p && y < q) {
            if (a[x].second < b[y].first + t)
                x++;
            else if (b[y].second + t < a[x].first)
                y++;
            else
                return true;
        }
        return false;
    };

    int c = 0;
    for (int i = l; i <= r; i++)
        if (is_common(i))
            c++;

    cout << c << '\n';
}
