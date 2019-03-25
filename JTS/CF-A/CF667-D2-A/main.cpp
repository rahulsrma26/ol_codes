//    Date : 2019-03-19
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/667/problem/A

#include <iostream>
#include <iomanip>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int d, h, v, e;
    cin >> d >> h >> v >> e;

    constexpr double pi = 3.141592653589793238;
    double r = pi * e * d * d * 0.25;

    if (r > v) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        double i = pi * h * d * d * 0.25;
        double t = 0.0;
        if(r < v)
            t = i / (v - r);
        cout << fixed << setprecision(12) << t;
    }
}
