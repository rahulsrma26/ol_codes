//    Date : 2019-03-13
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/799/problem/A

#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int r = [&]() {
        // total cycles
        int c = (n + k - 1) / k;
        // remaining time after building he first
        int b = (d + t - 1) / t; // floor(d/t)
        if (b * k >= n)
            return 0;
        int rc = c - b;
        int o1 = d + t*(((rc+1)/2 + k - 1)/k);
        int o2 = b*t + + t*((rc/2 + k - 1)/k);

        return max(o1, o2) < c*t ? 1 : 0;
    }();

    const string msg[] = {"NO", "YES"};
    cout << msg[r] << '\n';
}
