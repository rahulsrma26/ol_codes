//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/439/problem/B

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    sort(a.begin(), a.end());
    uint64_t s = 0;
    for (const auto& x : a) {
        s += (uint64_t)x * l;
        if (l > 1)
            l--;
    }
    cout << s << '\n';
}
