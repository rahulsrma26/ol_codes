//    Date : 2019-03-12
//  Auther : Rahul Sharma
// Problem : http://codeforces.com/contest/112/problem/A

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 0; i < (int)s1.length(); i++) {
        const auto c1 = tolower(s1[i]);
        const auto c2 = tolower(s2[i]);
        if (c1 < c2) {
            cout << -1 << '\n';
            return 0;
        } else if (c1 > c2) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
}