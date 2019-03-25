//    Date : 2019-03-26
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/492/problem/A

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    sort(a.begin(), a.end());
    int m = max(2 * a.front(), 2 * (l - a.back()));
    for (int i = 1; i < n; i++)
        m = max(m, a[i] - a[i - 1]);

    cout << fixed << setprecision(10) << m / 2.0 << '\n';
}
