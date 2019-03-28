//    Date : 2019-03-28
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/476/problem/B

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

template <class T>
T nCr(T n, T r) {
    if (r < 0 || r > n)
        return 0;
    if (r < n - r)
        r = n - r;
    if (r == 0)
        return T(1);
    T v{n};
    for (T i = 2; i <= r; i++)
        v = v * --n / i;
    return v;
}

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, r;
    cin >> s >> r;

    auto counter = [](const string& s) {
        int p = 0, n = 0;
        for (const auto& c : s)
            if (c == '+')
                p++;
            else if (c == '-')
                n++;
        return make_tuple(p, n);
    };

    auto [sp, sn] = counter(s);
    auto [rp, rn] = counter(r);
    int ep = sp - rp, en = sn - rn;

    double p = 0;
    if (0 <= ep && 0 <= en) {
        int et = ep + en;
        int w = nCr(et, ep);
        for (; (w & 1) == 0; w >>= 1)
            et--;
        p = w / pow(2, et);
    }
    cout << fixed << setprecision(12) << p << '\n';
}
