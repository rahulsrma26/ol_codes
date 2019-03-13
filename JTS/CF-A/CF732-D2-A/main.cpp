#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, r;
    cin >> k >> r;

    int b = 10;
    for (int i = 1; i < 10; i++) {
        auto l = (k * i) % 10;
        if (l == 0 || l == r) {
            b = i;
            break;
        }
    }

    cout << b << '\n';
}
