//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/79/problem/B

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<pair<int, int>> w;
    for (int i = 0, r, c; i < k; i++, w.push_back(make_pair(r, c)))
        cin >> r >> c;
    sort(w.begin(), w.end());

    const char* s[] = {"Carrots", "Kiwis", "Grapes"};

    for (int r, c; t--;) {
        cin >> r >> c;
        auto v = make_pair(r, c);
        auto vi = upper_bound(w.begin(), w.end(), v) - w.begin();
        int i = (r - 1) * m + c - 1;
        if (vi && w[vi - 1] == v)
            cout << "Waste" << '\n';
        else
            cout << s[(i - vi) % 3] << '\n';
    }
}
