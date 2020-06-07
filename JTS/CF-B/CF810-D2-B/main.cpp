//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/810/problem/B

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, f;
    cin >> n >> f;

    vector<int> extra(n);
    uint64_t s = 0;
    for (int i = 0, k, l; i < n; i++){
        cin >> k >> l;
        const int sell = min(k, l);
        extra[i] = max(0, min(2 * k, l) - sell);
        s += sell;
    }

    nth_element(extra.begin(), extra.begin() + f, extra.end(), greater<>());
    for (int i = 0; i < f; i++)
        s += extra[i];
    cout << s;
}
