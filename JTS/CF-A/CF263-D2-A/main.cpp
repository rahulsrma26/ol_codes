#include <iostream>
#include <cmath>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int n = 2;
    int x, y, p;
    for(y = -n; y <= n; y++){
        for(x = -n; x <= n; x++){
            cin >> p;
            if(p == 1){
                cout << abs(y) + abs(x) << '\n';
                return 0;
            }
        }
    }
}