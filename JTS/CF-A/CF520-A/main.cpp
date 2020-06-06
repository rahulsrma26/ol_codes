//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : https://codeforces.com/contest/520/problem/A

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    char v[26];
    string s;
    cin >> s;

    for(auto c: s)
        v[('a' <= c && c <= 'z')? c - 'a' : c - 'A'] = 1;

    cout << (std::accumulate(v, v + 26, 0) == 26 ? "YES" : "NO") << '\n';
}