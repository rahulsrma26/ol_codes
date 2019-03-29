//    Date : 2019-03-29
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/148/problem/B

#include <iostream>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;

    int b = 0;
    double x = t * vp / (vd - vp);
    if (x > 0) {
        t += x;
        while (t * vp < c) {
            t += x + f;
            x = t * vp / (vd - vp);
            t += x;
            b++;
        }
    }
    cout << b << '\n';
}
