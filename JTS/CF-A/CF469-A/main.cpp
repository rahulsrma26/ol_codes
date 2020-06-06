//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : https://codeforces.com/contest/469/problem/A

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define input(t, v) t v; cin >> v
#define sum(v) accumulate(v.begin(), v.end(), 0)
#define min(v) *min_element(v.begin(), v.end())
#define max(v) *max_element(v.begin(), v.end())
#define amin(v) (min_element(v.begin(), v.end()) - v.begin())
#define amax(v) (max_element(v.begin(), v.end()) - v.begin())

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input(int, n);
    string v(n + 1, 0);

    input(int, p);
    for(int i = 0, x; i < p; i++, v[x] = 1)
        cin >> x;

    input(int, q);
    for(int i = 0, x; i < q; i++, v[x] = 1)
        cin >> x;

    cout << (sum(v) == n ? "I become the guy.": "Oh, my keyboard!") << '\n';
}