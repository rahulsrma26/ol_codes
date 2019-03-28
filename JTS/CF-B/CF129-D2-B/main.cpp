//    Date : 2019-03-28
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/129/problem/B

#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    vector<unordered_set<int>> al(V);
    for (int i = 0, x, y; i < E; i++) {
        cin >> x >> y;
        al[x - 1].insert(y - 1);
        al[y - 1].insert(x - 1);
    }

    int n = 0;
    while (true) {
        vector<int> m;
        for (int u = 0; u < V; u++)
            if (al[u].size() == 1)
                m.push_back(u);
        if (m.size())
            n++;
        else
            break;
        for (auto& u : m)
            if (al[u].size()) {
                int v = *al[u].begin();
                al[v].erase(u);
                al[u].clear();
            }
    }

    cout << n << '\n';
}
