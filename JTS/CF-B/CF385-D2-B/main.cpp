//    Date : 2019-03-31
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/385/problem/B

#include <iostream>
#include <string>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int w = 0, n = s.length(), l = -1;
    for (auto k = s.find("bear"); k != string::npos; l = k, k = s.find("bear", k + 1))
        w += (k - l) * (n - k - 3);

    cout << w << '\n';
}
