#include <iostream>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int p = 0;
    for (int i = 0, x, y, z; i < n; i++, p += (x + y + z) / 2)
        cin >> x >> y >> z;

    cout << p << '\n';
}