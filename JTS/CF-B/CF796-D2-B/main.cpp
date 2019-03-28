//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/796/problem/B

#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, c = 1;
    cin >> n >> m >> k;

    vector<char> a(n + 1);
    for (int i = 0, x; i < m; i++, a[x] = 1)
        cin >> x;

    for (int i = 0, x, y; i < k; i++) {
        if (a[c])
            break;
        cin >> x >> y;
        if (x == c)
            c = y;
        else if (y == c)
            c = x;
    }

    cout << c << '\n';
}
