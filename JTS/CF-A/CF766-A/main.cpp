//    Date : 2020-06-05
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/766/problem/A

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

    string a, b;
    getline(cin, a);
    getline(cin, b);

    if(a == b)
        cout << -1 << '\n';
    else
        cout << max(a.length(), b.length()) << '\n';
}