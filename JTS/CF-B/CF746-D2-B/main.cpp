//    Date : 2019-03-19
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/746/problem/B

#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);

    string o(n, ' ');
    if (n & 1) {
        for (int i = 1, r = (n - 1) / 2, l = r - 1; i <= n; i++)
            o[(i & 1) ? r++ : l--] = s[i - 1];
    } else {
        for (int i = 0, l = (n - 1) / 2, r = l + 1; i < n; i++)
            o[(i & 1) ? r++ : l--] = s[i];
    }
    cout << o << '\n';
}
