//    Date : 2019-03-12
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/112/problem/A

#include <bits/stdc++.h>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i < s1.length(); i++) {
        if (tolower(s1[i]) < tolower(s2[i])) {
            cout << -1 << '\n';
            return 0;
        } else if (tolower(s1[i]) > tolower(s2[i])) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
}
