#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for(auto& x: a)
        cin >> x;

    sort(a.begin(), a.end());

    for(const auto& x: a)
        cout << x << ' ';
}