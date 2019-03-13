#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    int s[2] = {};
    for (int i = 0, l = 0, r = n - 1; i < n; i++)
        s[i & 1] += a[l] >= a[r] ? a[l++] : a[r--];

    cout << s[0] << ' ' << s[1] << '\n';
}
