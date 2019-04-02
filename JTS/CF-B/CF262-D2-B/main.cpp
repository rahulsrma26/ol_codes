//    Date : 2019-04-02
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/262/problem/B

#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k >> x;

    int s = 0, a = abs(x), i = 0, nn = 0;
    for (; x < 0 && i<k; cin>> x) {
        s += -x;
        a = min(a, -x);
        i++;
        if (i == n)
            break;
    }

    for (nn = i; i<n; cin>> x) {
        s += x;
        a = min(a, abs(x));
        if (x < 0)
            nn++;
        i++;
        if (i == n)
            break;
    }

    if (nn < k && ((k - nn) & 1))
        s -= 2 * a;

    cout << s << '\n';
}
