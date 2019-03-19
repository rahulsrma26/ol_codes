//    Date : 2019-03-18
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/287/problem/B

#include <bits/stdc++.h>

using num = long long;

template <class T, class Calc>
T bs(T n, T l, T r, Calc calc) {
    T cl = calc(l);
    if (n <= cl)
        return l;
    T cr = calc(r);
    if (n > cr)
        return -1;
    while (l < r) {
        T m = (l + r) / 2;
        T cm = calc(m);
        if (n < cm)
            r = m;
        else if (n > cm)
            l = m + 1;
        else
            return m;
    }
    return l;
}

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    num n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << '0' << '\n';
    } else {
        auto outputs = [=](num i) { return i * k - (i + 2) * (i - 1) / 2; };
        cout << bs(n, (num)1, k, outputs) << '\n';
    }
}
