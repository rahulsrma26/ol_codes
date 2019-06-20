//    Date : 2019-06-20
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/617/problem/B

#include <iostream>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l = -1;
    cin >> n;

    uint64_t t = 1;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x) {
            if(l != -1)
                t *= i - l;
            l = i;
        }
    }
    cout << (l == -1 ? 0 : t) << '\n';
}
