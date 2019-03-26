//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/451/problem/B

#include <iostream>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[2] = {1, 1}, k = 0, p = 0, pp = -1, l = -1, r = -1;

    for (int i = 1, x; i <= n + 1; i++) {
        if (i <= n)
            cin >> x;
        else
            x = 1'000'000'001;

        if (k == 0 && p > x) {
            a[k++] = i - 1, l = pp, r = p;
        } else if (k == 1 && p < x) {
            if (r < x && l < p)
                a[k++] = i - 1;
            else
                k = 3;
        } else if (k == 2 && p > x) {
            k = 3;
        }
        pp = p;
        p = x;
    }

    if (k < 3) {
        cout << "yes" << '\n';
        cout << a[0] << ' ' << a[1] << '\n';
    } else {
        cout << "no" << '\n';
    }
}
