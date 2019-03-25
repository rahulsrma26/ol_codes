//    Date : 2019-03-18
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/404/problem/A

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cin.ignore();
    string s;
    char d[26] = {}, o[26] = {};
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < n; j++) {
            if (i == j || i == (n - 1 - j))
                d[s[j] - 'a'] = 1;
            else
                o[s[j] - 'a'] = 1;
        }
    }
    int ot = accumulate(d, d + 26, 0);
    int di = accumulate(o, o + 26, 0);
    cout << (s[0] != s[1] && ot == 1 && di == 1 ? "YES" : "NO");
}
