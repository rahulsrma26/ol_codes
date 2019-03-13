//    Date : 2019-03-13
//  Auther : Rahul Sharma
// Problem : http://codeforces.com/contest/709/problem/A

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, b, d;
    cin >> n >> b >> d;

    int e = 0;
    for (int i = 0, x, s = 0; i < n; i++) {
        cin >> x;
        if (x <= b) {
            s += x;
            if (s > d) {
                s = 0;
                e++;
            }
        }
    }
    cout << e << '\n';
}
