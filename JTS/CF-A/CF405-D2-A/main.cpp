//    Date : 2019-03-12
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/405/problem/A

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for(auto& x: a)
        cin >> x;

    sort(a.begin(), a.end());

    for(const auto& x: a)
        cout << x << ' ';
}