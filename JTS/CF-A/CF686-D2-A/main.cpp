//    Date : 2019-03-14
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/686/problem/A

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, d = 0;
    long long s;
    cin >> n >> s;

    for (int i = 0, x; i < n; i++) {
        char c;
        cin >> c >> x;
        if (c == '+')
            s += x;
        else if (s < x)
            d++;
        else
            s -= x;
    }

    cout << s << ' ' << d << '\n';
}
