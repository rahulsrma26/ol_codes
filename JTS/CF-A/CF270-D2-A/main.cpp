//    Date : 2019-03-19
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/270/problem/A

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        cout << (360 % (180 - a) == 0 ? "YES" : "NO") << '\n';
    }
}
