//    Date : 2019-03-25
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/47/problem/B

#include <iostream>
#include <string>
#include <vector>

constexpr int n = 3;

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> al(n);

    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if (s[1] == '>')
            al[s[0] - 'A'].push_back(s[2] - 'A');
        else
            al[s[2] - 'A'].push_back(s[0] - 'A');
    }

    vector<int> l;
    vector<int> v(n);
    bool dag = true;

    auto visit = [&](int i) {
        auto lambda = [&](int i, const auto& ff) -> void {
            if (v[i] == 1)
                return;
            if (v[i] == -1) {
                dag = false;
                return;
            }
            v[i] = -1;
            for (auto& u : al[i])
                ff(u, ff);
            v[i] = 1;
            l.push_back(i);
        };
        lambda(i, lambda);
    };

    for (int i = 0; dag && i < n; i++)
        if (!v[i])
            visit(i);

    if(dag)
        for (auto& x: l)
            cout << (char)(x + 'A');
    else
        cout << "Impossible";
}
