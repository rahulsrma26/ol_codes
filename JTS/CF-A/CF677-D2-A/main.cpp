//    Date : 2019-03-12
//  Auther : Rahul Sharma
// Problem : http://codeforces.com/contest/677/problem/A

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;

    int w = n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x > h)
            w++;
    }

    cout << w << '\n';
}