//    Date : 2019-03-14
//  Auther : Rahul Sharma
// Problem : http://codeforces.com/contest/443/problem/A

#include <algorithm>
#include <iostream>
#include <string>
#include <numeric>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin, s);

    int u[26] = {};
    for(auto c: s)
        if('a' <= c && c<= 'z')
            u[c - 'a'] = 1;

    cout << accumulate(u, u + 26, 0) << '\n';
}
