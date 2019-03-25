//    Date : 2019-03-25
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/463/problem/B

#include <iostream>
#include <algorithm>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int m;
    cin >> m;
    for (int i = 1, x; i < n; i++, m = max(m, x))
        cin >> x;

    cout << m << '\n';
}
