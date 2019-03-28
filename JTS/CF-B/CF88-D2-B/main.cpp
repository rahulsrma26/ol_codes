//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/88/problem/B

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int r, c, l;
    cin >> r >> c >> l;
    cin.ignore();

    vector<string> m(r);
    for (auto& s : m)
        cin >> s;

    string p(128, -1);
    vector<pair<int, int>> S;
    for (int y = 0; y < r; y++)
        for (int x = 0; x < c; x++)
            if (m[y][x] == 'S')
                S.push_back({y, x});
            else
                p[m[y][x]] = 0;

    auto effort = [&](int y, int x) {
        int md = l + 1;
        for (const auto& [sy, sx] : S) {
            int d = ceil(sqrt((x - sx) * (x - sx) + (y - sy) * (y - sy)));
            if (d < md)
                md = d;
        }
        return md <= l ? 0 : 1;
    };

    if (!S.empty())
        for (int y = 0; y < r; y++)
            for (int x = 0; x < c; x++)
                if (m[y][x] != 'S' && p[m[y][x] - 32])
                    p[m[y][x] - 32] = effort(y, x);

    int q;
    cin >> q;
    cin.ignore();
    string t;
    cin >> t;

    int u = 0;
    for (const auto& k : t) {
        if (p[k] == -1) {
            u = -1;
            break;
        } else {
            u += p[k];
        }
    }
    cout << u << '\n';
}
