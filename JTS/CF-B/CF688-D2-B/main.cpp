//    Date : 2019-03-27
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/688/problem/B

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    cout << s;
    reverse(s.begin(), s.end());
    cout << s;
}