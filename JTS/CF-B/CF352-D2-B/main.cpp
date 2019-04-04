//    Date : 2019-04-04
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/352/problem/B

#include <iostream>
#include <map>
#include <vector>

struct AP {
    int count;
    int diff;
    int last;
};

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t = 0;
    cin >> n;

    map<int, AP> s;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (auto r = s.find(x); r != s.end()) {
            auto& v = r->second;
            if (v.count) {
                if (v.count == 1)
                    v.diff = i - v.last;
                else if (i - v.last != v.diff) {
                    v.count = 0;
                    t--;
                    continue;
                }
                v.last = i;
                v.count++;
            }
        } else {
            s.insert({x, {1, 0, i}});
            t++;
        }
    }

    cout << t << '\n';
    for (auto& [k, v] : s)
        if (v.count)
            cout << k << ' ' << v.diff << '\n';
}
