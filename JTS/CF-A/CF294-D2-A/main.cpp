#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int m;
    cin >> m;

    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        if (x > 1)
            a[x - 2] += y - 1;
        if (x < n)
            a[x] += a[x - 1] - y;
        a[x - 1] = 0;
        // for (auto x : a)
        //     cout << x << ' ';
        // cout << '\n';
    }

    for (auto x : a)
        cout << x << '\n';
}
