#include <algorithm>
#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m = 1, l;
    cin >> l;

    for (int i = 1, x; i < n; i++) {
        cin >> x;
        if (x != l)
            m++;
        l = x;
    }

    cout << m << '\n';
}