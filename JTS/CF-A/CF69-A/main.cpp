//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : https://codeforces.com/contest/69/problem/A

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int x, y, z;
    cin >> x >> y >> z;

    for(int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }

    cout << (x == 0 && y == 0 && z == 0 ? "YES": "NO") << '\n';
}