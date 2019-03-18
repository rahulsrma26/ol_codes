//    Date : 2019-03-13
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/431/problem/A

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a[4];
    for(auto& x: a)
        cin >> x;

    string s;
    cin.ignore();
    getline(cin, s);

    int cal = 0;
    for(auto c: s)
        cal += a[c - '1'];

    cout << cal << '\n';
}
