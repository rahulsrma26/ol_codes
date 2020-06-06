//    Date : 2020-06-06
//  Author : Rahul Sharma
// Problem : https://codeforces.com/contest/160/problem/A

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

    vector<int> a(n);
    for(auto& x: a)
        cin >> x;

    auto total = std::accumulate(a.begin(), a.end(), 0);
    int amount = (total % 2 == 0) ? (total / 2 + 1) : (total - total/2);
    sort(a.begin(), a.end());

    int i = n - 1;
    for(int s = 0; s < amount; i--)
        s += a[i];

    cout << n - i - 1 << '\n';
}