//    Date : 2019-03-15
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/216/problem/A

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct vertex {
    int l, r;

    vertex() : l(0), r(0) {}

    void add(int i) {
        if (l == 0)
            l = i;
        else
            r = i;
    }

    int get_other(int x) { return x == l ? r : l; }
};

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, e;
    cin >> n >> e;

    vector<vertex> v(n + 1);
    for (int i = 0, x, y; i < e; i++) {
        cin >> x >> y;
        v[x].add(y);
        v[y].add(x);
    }

    int s = 0;
    vector<int> team(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!team[i]) {
            team[i] = 1;
            int ls = 1, loop = 0;
            for (int p = i, c = v[p].l; c; ls++) {
                if (team[c]) {
                    loop = 1;
                    break;
                }
                team[c] = 1;
                int x = v[c].get_other(p);
                p = c;
                c = x;
            }
            if (!loop) {
                for (int p = i, c = v[p].r; c; ls++) {
                    team[c] = 1;
                    int x = v[c].get_other(p);
                    p = c;
                    c = x;
                }
            }
            else
                ls -= ls&1;
            s += ls;
        }
    }

    if(s&1)
        s -= s&1;

    cout << n - s << '\n';
}
