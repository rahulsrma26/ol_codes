//    Date : 2019-03-12
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/344/problem/A

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m = 1, l;
    cin >> l;

    for (int i = 1, x; i < n; i++) {
        cin >> x;
        if (x != l)
            m++;
        l = x;
    }

    cout << m << '\n';
}
