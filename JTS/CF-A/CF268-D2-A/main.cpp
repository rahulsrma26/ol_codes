#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    unordered_map<int, int> m;
    for (int i = 0, x; i < n; i++, m[x]++)
        cin >> v[i] >> x;

    int s = 0;
    for (int i = 0; i < n; i++)
        s += m[v[i]];
    cout << s << '\n';
}