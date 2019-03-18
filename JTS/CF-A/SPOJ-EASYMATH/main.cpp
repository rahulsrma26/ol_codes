//    Date : 2019-03-15
//  Author : Rahul Sharma
// Problem : https://www.spoj.com/problems/EASYMATH/

#include <algorithm>
#include <iostream>
#include <vector>

using num = long long;
using unum = unsigned long long;

#define f(x, y) (x / ((a + x * d) * (a + y * d)))
#define g(x, y, z) (x / ((a + x * d) * (a + y * d) * (a + z * d)))

template <class T>
typename std::enable_if<std::is_unsigned<T>::value, T>::type GCD(T u, T v) {
    int shift;
    if (u == 0)
        return v;
    if (v == 0)
        return u;

    for (shift = 0; ((u | v) & 1) == 0; ++shift) {
        u >>= 1;
        v >>= 1;
    }

    while ((u & 1) == 0)
        u >>= 1;

    do {
        while ((v & 1) == 0)
            v >>= 1;
        if (u > v) {
            T t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);

    return u << shift;
}

inline num LCM(num a, num b){
    return a / GCD((unum)a, (unum)b) * b;
}

num get_multiples(num x, std::vector<num> a) {
    int n = a.size();
    num s = 0;
    for(int i=1; i< (1<<n); i++){
        num lcm = 1;
        for(int j=0; j<n; j++)
            if(i&(1<<j))
                lcm = std::min(x+1, LCM(lcm, a[j]));
        s += ((__builtin_popcount(i) & 1) ? x : -x)/lcm;
    }
    return s;
}

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        num n, m, a, d;
        cin >> n >> m >> a >> d;

        vector<num> v{a, a+d, a+2*d, a+3*d, a+4*d};
        num t = get_multiples(m, v) - get_multiples(n - 1, v);
        cout << m - n + 1 - t << '\n';
    }
}
