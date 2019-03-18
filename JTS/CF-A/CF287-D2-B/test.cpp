//    Date : 2019-03-18
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/287/problem/B

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

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
            r = m - 1;
        else if (n > cm)
            l = m + 1;
    }
    return l;
}

template <class T, class Calc>
T ss(T n, T l, T r, Calc calc) {
    for (; l <= r; l++)
        if (n <= calc(l))
            return l;
    return -1;
}

void test(int t, int kl) {
    using namespace std;
    std::default_random_engine rnd;
    std::uniform_int_distribution<int> ks(2, kl);
    int f = 0;
    for (int i = 0; i < t; i++) {
        int k = ks(rnd);
        std::uniform_int_distribution<int> ns(1, k * k);
        int n = ns(rnd);
        auto calc = [=](int i) { return i * k - (i + 2) * (i - 1) / 2; };
        auto r1 = ss(n, 1, k, calc);
        auto r2 = bs(n, 1, k, calc);
        if (r1 != r2) {
            std::cout << r1 << " != " << r2 << '\n';
            std::cout << n << ", " << k << '\n';
            f++;
        }
    }
    cout << f << " out of " << t << " failed.\n";
}

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    test(1'000'000, 20);
}
