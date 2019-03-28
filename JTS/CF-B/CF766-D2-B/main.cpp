//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/766/problem/B

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    sort(a.begin(), a.end());
    int p = 0;
    for (int i = 2; i < n; i++)
        if (a[i - 2] + a[i - 1] > a[i] && (p = 1))
            break;
    cout << (p ? "YES" : "NO") << '\n';
}
