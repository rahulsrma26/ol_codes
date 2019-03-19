//    Date : 2019-03-19
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/66/problem/B

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    vector<int> l(n, 1); // monotonically decresing left chain length
    for (int i = 1; i < n; i++)
        l[i] = a[i - 1] <= a[i] ? l[i - 1] + 1 : 1;

    vector<int> r(n, 1); // monotonically decresing right chain length
    for (int i = n - 2; i >= 0; i--)
        r[i] = a[i] >= a[i + 1] ? r[i + 1] + 1 : 1;

    int m = 0;
    for (int i = 0; i < n; i++)
        m = max(m, l[i] + r[i] - 1);
    cout << m << '\n';
}
