//    Date : 2019-03-26
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/227/problem/B

#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> idx(n + 1);
    for (int i = 1, x; i <= n; idx[x] = i++)
        cin >> x;

    uint64_t a{0}, b{0};

    int m;
    cin >> m;
    for (int x; m--; a += idx[x], b += n - idx[x] + 1)
        cin >> x;

    cout << a << ' ' << b << '\n';
}
