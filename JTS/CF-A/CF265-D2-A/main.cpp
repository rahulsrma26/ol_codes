//    Date : 2019-04-05
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/265/problem/A

#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    const int n = a.length(), m = b.length();
    int i = 0, j = 0;

    while (i < n && j < m)
        if (a[i] == b[j++])
            i++;

    cout << i + 1 << '\n';
}
