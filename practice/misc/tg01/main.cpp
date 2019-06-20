#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n), p(n);
        for (auto& x : v)
            cin >> x;
        for (auto& x : p)
            cin >> x;
        sort(v.begin(), v.end());
        sort(p.begin(), p.end());
        bool win = true;
        for (int i = 0; i < n; i++)
            if (v[i] > p[i]) {
                win = false;
                break;
            }
        cout << (win ? "WIN" : "LOSE") << '\n';
    }
}
