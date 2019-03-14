//    Date : 2019-03-14
//  Auther : Rahul Sharma
// Problem : http://codeforces.com/contest/490/problem/A

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> a(3);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x - 1].push_back(i + 1);
    }

    int t = min_element(a.begin(), a.end(),
                        [](const auto &a, const auto &b) {
                            return a.size() < b.size();
                        })
                ->size();
    cout << t << '\n';

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++)
            cout << a[j][a[j].size() - t + i] << ' ';
        cout << '\n';
    }
}
