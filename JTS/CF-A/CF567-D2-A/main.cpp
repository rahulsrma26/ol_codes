//    Date : 2019-03-15
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/567/problem/A

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    cout << a[1] - a[0] << ' ' << a[n - 1] - a[0] << '\n';
    for (int i = 1; i < n - 1; i++)
        cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) << ' '
             << max(a[i] - a[0], a[n - 1] - a[i]) << '\n';
    cout << a[n - 1] - a[n - 2] << ' ' << a[n - 1] - a[0];
}
